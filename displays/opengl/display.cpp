//
// display.cpp for sfml in /home/swll/Documents/projets/c++/nibbler-2015-guina_b/displays/sfml
// 
// Made by roger ingouacka
// Login   <ingoua_r@epitech.net>
// 
// Started on  Tue Mar 13 10:31:11 2012 roger ingouacka
// Last update Sun Mar 18 14:26:46 2012 roger ingouacka
//

#include <iostream>
#include <stdexcept>
#include <sstream>

#include <GL/gl.h> 

#include "Direction.hpp"
#include "Game.hpp"
#include "DisplayOpenGL.hpp"

extern "C" IDisplay* IDISPLAY_MAKE_SYMBOL(int map_width, int map_height)
{
  return (new DisplayOpenGL(map_width, map_height));
}

DisplayOpenGL::DisplayOpenGL(int map_width, int map_height)
{
    if (map_width * unit_size > max_window_width || map_height * unit_size > max_window_height)
    {
        std::stringstream ss;

        ss << "this map would exceed the maximum resolution of " << max_window_width << 'x' << max_window_height;
        throw std::invalid_argument(ss.str());
    }

  m_win.create(sf::VideoMode(map_width * unit_size, map_height * unit_size), "Nibbler: OpenGL");
  glMatrixMode(GL_PROJECTION);
  glOrtho(0.f, map_width, map_height, 0.f, 0, 1.f);
}

bool DisplayOpenGL::get_input(Direction& snake_direction)
{
  sf::Event Event;

  while (m_win.pollEvent(Event))
    {
      if (Event.type == sf::Event::Closed)
	return (false);

    if (Event.type == sf::Event::Resized)
        glViewport(0, 0, Event.size.width, Event.size.height);

      if (Event.type == sf::Event::KeyPressed)
      {
          switch (Event.key.code)
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
      }
    }
  return (true);
}

void DisplayOpenGL::display(Game const& game)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3ub(0, 200, 0);
    for (SnakePosition::const_iterator it = game.snake_begin(); it != game.snake_end(); it++)
    {
      glPushMatrix();
      glTranslatef(it->first + .1f, it->second + .1f, 0.f);
      glBegin(GL_QUADS);
        glVertex2f(0.f, .8f);
        glVertex2f(.8f, .8f);
        glVertex2f(.8f, 0.f);
        glVertex2f(0.f, 0.f);
      glEnd();
      glPopMatrix();
    }

    glColor3ub(150, 0, 0);
    for (FoodPosition::const_iterator it = game.food_begin(); it != game.food_end(); it++)
    {
      glPushMatrix();
      glTranslatef(it->first + .18f, it->second + .18f, 0.f);
      glBegin(GL_QUADS);
        glVertex2f(0.f, .64f);
        glVertex2f(.64f, .64f);
        glVertex2f(.64f, 0.f);
        glVertex2f(0.f, 0.f);
      glEnd();
      glPopMatrix();
    }

    m_win.display();
}
