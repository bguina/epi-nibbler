//
// Made by benoit guina
// Login   <guina_b@epitech.net>
//

#ifndef HPP_DISPLAYDUMMY
#define HPP_DISPLAYDUMMY

#include "IDisplay.hpp"

class DisplayDummy : public IDisplay
{
    public:
        DisplayDummy(int map_width, int map_height);
        ~DisplayDummy();

        virtual bool get_input(Direction& snake_direction);

        virtual void display(Game const& game);
};

#endif
