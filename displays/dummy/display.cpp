//
// Made by benoit guina
// Login   <guina_b@epitech.net>
//

#include <iostream>
#include <algorithm>
#include <cstdlib>

#include "Direction.hpp"
#include "Game.hpp"
#include "DisplayDummy.hpp"

extern "C" IDisplay* IDISPLAY_MAKE_SYMBOL(int map_width, int map_height)
{
  return (new DisplayDummy(map_width, map_height));
}

DisplayDummy::DisplayDummy(int map_width, int map_height)
{
  (void)map_width;
  (void)map_height;
  std::cerr << "DisplayDummy loaded" << std::endl;
}

DisplayDummy::~DisplayDummy()
{
  std::cerr << "DisplayDummy unloaded" << std::endl;
}

bool DisplayDummy::get_input(Direction& snake_direction)
{
    if (!(rand() % 2))
      snake_direction.set(Direction::EDirection(rand() % Direction::DIRECTION_TOTAL));
    return (true);
}

void DisplayDummy::display(Game const& game)
{
    for (int y = -1; y < game.map_height() + 1; y++)
    {
        for (int x = -1; x < game.map_width() + 1; x++)
            std::cout << ((game.is_free(x, y))  ?   ' ' :
                          (game.is_food(x, y))  ?   'o' :
                          (game.is_snake(x, y)) ?   'S' :
                                                    '#' );
        std::cout << std::endl;
    }
}
