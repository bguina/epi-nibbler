//
// Made by benoit guina
// Login   <guina_b@epitech.net>
//

#ifndef HPP_ICONTROLLER
#define HPP_ICONTROLLER

#include "Direction.hpp"

class Snake;
class Game;

class IController
{
    public:
        virtual Direction play(Snake const& snake, Game const& game) = 0;
};

#endif
