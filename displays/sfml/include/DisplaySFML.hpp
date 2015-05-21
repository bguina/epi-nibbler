//
// DisplaySfml.hpp for ingoua_r in /home/swll/Documents/projets/c++/nibbler-2015-guina_b/displays/dummy/include
// 
// Made by roger ingouacka
// Login   <ingoua_r@epitech.net>
// 
// Started on  Tue Mar 13 10:24:28 2012 roger ingouacka
// Last update Thu Mar 15 11:10:53 2012 roger ingouacka
//

#ifndef HPP_DISPLAYSFML
#define HPP_DISPLAYSFML

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "IDisplay.hpp"

class DisplaySFML : public IDisplay
{
public:
  static unsigned int const unit_size = 20;
  static unsigned int const max_window_width = 1280;
  static unsigned int const max_window_height = 1024;

  DisplaySFML(int map_width, int map_height);

  virtual bool get_input(Direction& snake_direction);

  virtual void display(Game const& game);

protected:
  sf::RenderWindow m_win;
  sf::Texture m_txtr_snake;
  sf::Sprite m_sprt_snake;
  sf::Texture m_txtr_food;
  sf::Sprite m_sprt_food;
};

#endif
