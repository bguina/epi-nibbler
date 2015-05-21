//
// Made by benoit guina
// Login   <guina_b@epitech.net>
//

#ifndef HPP_GAME
#define HPP_GAME

#include "Snake.hpp"
#include "Map.hpp"

class IDisplay;
class Map;

class Game
{
    public:
        static char const* const usage;
        static unsigned int const unit_clock = 200;

        // Interface for the entry point
        static void run(int ac, char const* const* av);

        // Interface for the display (read only)
        int map_width() const;
        int map_height() const;

        SnakePosition::const_iterator snake_begin() const;
        SnakePosition::const_iterator snake_end() const;
        Direction const& snake_direction() const;

        FoodPosition::const_iterator food_begin() const;
        FoodPosition::const_iterator food_end() const;

        bool is_free(int x, int y) const;
        bool is_food(int x, int y) const;
        bool is_snake(int x, int y) const;

        
    protected:
        static bool m_instanciated;

        Game(int ac, char const* const* av);
        ~Game();
        void run_instance();
        bool put_food(int n=1);

        void* m_display_lib;
        IDisplay* m_display;
        Map* m_map;
        Snake* m_snake;
};

#endif
