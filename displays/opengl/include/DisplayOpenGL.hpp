//
// DisplaySfml.hpp for ingoua_r in /home/swll/Documents/projets/c++/nibbler-2015-guina_b/displays/dummy/include
// 
// Made by roger ingouacka
// Login   <ingoua_r@epitech.net>
// 
// Started on  Tue Mar 13 10:24:28 2012 roger ingouacka
// Last update Sun Mar 18 14:17:31 2012 roger ingouacka
//

#ifndef HPP_DISPLAYOPENGL
#define HPP_DISPLAYOPENGL

#include <SFML/Window.hpp>
#include "IDisplay.hpp"

class DisplayOpenGL : public IDisplay
{
public:
  static unsigned int const unit_size = 20;
  static unsigned int const max_window_width = 1280;
  static unsigned int const max_window_height = 1024;

  DisplayOpenGL(int map_width, int map_height);
  virtual bool get_input(Direction& snake_direction);
  virtual void display(Game const& game);

protected:
  sf::Window m_win;
};

#endif
