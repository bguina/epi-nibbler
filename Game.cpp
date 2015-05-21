//
// Made by benoit guina
// Login   <guina_b@epitech.net>
//

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>

extern "C" {
#include <unistd.h>
#include <dlfcn.h>
}

#include "IDisplay.hpp"
#include "Map.hpp"
#include "Snake.hpp"
#include "Game.hpp"

char const* const Game::usage = "width height display_library\n"
            "  with width >= 4 (can depend on the display library)\n"
            "       height >= 4 (can depend on the display library)\n"
            "       display_library a valid nibbler display library";

bool Game::m_instanciated = false;


void Game::run(int ac, char const* const* av)
{
    if (!m_instanciated)
    {
        Game game(ac, av);

        game.run_instance();
    }
    else
        throw std::logic_error("game instanciated twice");
}

int Game::map_width() const
{
    return (m_map->width());
}

int Game::map_height() const
{
    return (m_map->height());
}

SnakePosition::const_iterator Game::snake_begin() const
{
    return (m_snake->begin());
}

SnakePosition::const_iterator Game::snake_end() const
{
    return (m_snake->end());
}

Direction const& Game::snake_direction() const
{
    return (m_snake->direction());
}

FoodPosition::const_iterator Game::food_begin() const
{
    return (m_map->food_begin());
}

FoodPosition::const_iterator Game::food_end() const
{
    return (m_map->food_end());
}

bool Game::is_free(int x, int y) const
{
    return (!(m_map->is_wall(x, y) || is_food(x, y) || is_snake(x, y)));
}

bool Game::is_food(int x, int y) const
{
    return (m_map->is_food(x, y));
}

bool Game::is_snake(int x, int y) const
{
    return (m_snake->is_occupied(x, y));
}

Game::Game(int ac, char const* const* av)
    : m_display_lib(0), m_display(0), m_map(0), m_snake(0)
{
    int map_width;
    int map_height;
    std::string display_lib;
    IDisplay* (*make_display)(int, int);

    if (--ac != 3)
        throw std::invalid_argument("invalid argument number");

    {   // Parse the arguments
        std::stringstream ss;
        
        ss << av[1] << ' ' << av[2];
        ss >> map_width; ss >> map_height;
        display_lib = av[3];
    }

    {   // Load the display library
        if (!(m_display_lib = dlopen(display_lib.c_str(), RTLD_NOW)) ||
            !(make_display = reinterpret_cast<IDisplay* (*)(int, int)>(dlsym(m_display_lib, "make_nibbler_display"))))
            throw std::invalid_argument(std::string("display library ") + dlerror());
    }

    {   // Construct the subcomponents of the game
        if (!(m_display = make_display(map_width, map_height)))
            throw std::runtime_error(display_lib + " failed to instanciate a display");
        m_map = new Map(map_width, map_height);
        m_snake = new Snake(map_width / 2, map_height / 2);
    }

    put_food(5);

    Game::m_instanciated = true;
}

Game::~Game()
{
    delete m_display;
    delete m_map;
    delete m_snake;

    {   // Unload the display library
        if (dlclose(m_display_lib))
            std::cerr << dlerror() << std::endl;
    }

    Game::m_instanciated = false;
}

void Game::run_instance()
{
    bool run(true);
    std::clock_t before(0);

    while (run)
    {   // Loop start

        {   // Display
            m_display->display(*this);
        }

        {   // Slow down the game
            std::clock_t now(std::clock());

            usleep((unit_clock * 1000) - ((float)(now - before) / CLOCKS_PER_SEC * 1000000));
            before = now;
        }

        {   // Handle events
            Direction new_snake_dir(m_snake->direction());
	    
            run = m_display->get_input(new_snake_dir);
            m_snake->turn(new_snake_dir.get());
        }

        if (run)
        {   // Trigger actions
            bool takes_food(false);

            {   // Check if the snake will take food on its next move
                Position next_pos(*m_snake->begin());

                m_snake->direction().move(next_pos.first, next_pos.second);
                takes_food = m_map->remove_food(next_pos.first, next_pos.second);
            }

            {   // Make the move
                run = false;
                if (!m_snake->move(takes_food))
                    std::cout << "game end: you died bitting yourself" << std::endl;
                else if (m_map->is_wall(m_snake->begin()->first, m_snake->begin()->second))
                    std::cout << "game end: you died running into a wall" << std::endl;
                else
                    run = true;
            }

            if (takes_food)
                put_food(2);
        }
        else
            std::cout << "game end: you left the game" << std::endl;

    }   // Loop end
}

bool Game::put_food(int n)
{
    while (n > 0)
    {
        bool free_room(false);

        {   // First, check if these is still space for it
            for (int y = -1; !free_room && y < m_map->height(); y++)
                for (int x = -1; !free_room && x < m_map->width(); x++)
                    if (is_free(x, y))
                        free_room = true;

            if (!free_room)
                return (false);
        }

        {   // If there is, select a random free spot and put food there
            int new_food[2];

            if (free_room) do do
            {
                new_food[0] = rand() % m_map->width();
                new_food[1] = rand() % m_map->height();
            }
            while (m_snake->is_occupied(new_food[0], new_food[1]));
            while (!m_map->put_food(new_food[0], new_food[1]));
        }

        n--;
    }

    return (true);
}
