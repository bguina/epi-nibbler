//
// DisplaySFML.cpp for sfml in /home/swll/Documents/projets/c++/nibbler-2015-guina_b/DisplaySFMLs/sfml
// 
// Made by roger ingouacka
// Login   <ingoua_r@epitech.net>
// 
// Started on  Tue Mar 13 10:31:11 2012 roger ingouacka
// Last update Sat Mar 17 17:19:52 2012 essomba mpongo
//

#include <iostream>
#include <stdexcept>
#include <sstream>

#include "Direction.hpp"
#include "Game.hpp"
#include "DisplaySFML.hpp"

extern "C" IDisplay* IDISPLAY_MAKE_SYMBOL(int map_width, int map_height)
{
  return (new DisplaySFML(map_width, map_height));
}

DisplaySFML::DisplaySFML(int map_width, int map_height)
{
  if (map_width * unit_size > max_window_width || map_height * unit_size > max_window_height)
  {
    std::stringstream ss;

    ss << "this map would exceed the maximum resolution of " << max_window_width << 'x' << max_window_height;
    throw std::invalid_argument(ss.str());
  }

  m_win.create(sf::VideoMode(map_width * unit_size, map_height * unit_size), "Nibbler: SFML");

  if (!m_txtr_snake.loadFromFile("res/snake.png"))
    throw std::runtime_error("could not load \"snake.png\"");
  m_sprt_snake.setTexture(m_txtr_snake);
  if (!m_txtr_food.loadFromFile("res/food.png"))
    throw std::runtime_error("could not load \"food.png\"");
  m_sprt_food.setTexture(m_txtr_food);
}

bool DisplaySFML::get_input(Direction& snake_direction)
{
  sf::Event event;

  while (m_win.pollEvent(event))
  {
    switch (event.type)
    {
      case sf::Event::Closed:
        return (false);

      case sf::Event::KeyPressed:
        switch (event.key.code)
        {
          case sf::Keyboard::Escape:
            return (false);
          case sf::Keyboard::Left:
            snake_direction.set(Direction::DIRECTION_LEFT);
            break;
          case sf::Keyboard::Right:
            snake_direction.set(Direction::DIRECTION_RIGHT);
            break;
          case sf::Keyboard::Up:
            snake_direction.set(Direction::DIRECTION_UP);
            break;
          case sf::Keyboard::Down:
            snake_direction.set(Direction::DIRECTION_DOWN);
            break;
          default: ;
        }

      default: ;
    }
  }
  
  return (true);
}

void DisplaySFML::display(Game const& game)
{
    m_win.clear();

    for (SnakePosition::const_iterator it = game.snake_begin(); it != game.snake_end(); it++)
    {
        m_sprt_snake.setPosition(it->first * unit_size, it->second * unit_size);
        m_win.draw(m_sprt_snake);
    }
    for (FoodPosition::const_iterator it = game.food_begin(); it != game.food_end(); it++)
    {
        m_sprt_food.setPosition(it->first * unit_size, it->second * unit_size);
        m_win.draw(m_sprt_food);
    }

    m_win.display();
}
