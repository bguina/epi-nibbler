//
// Made by benoit guina
// Login   <guina_b@epitech.net>
//

#ifndef HPP_DISPLAY
#define HPP_DISPLAY

#define IDISPLAY_MAKE_SYMBOL    make_nibbler_display

/*
**  Display librarie must implement the following C function to instanciate
**  the nibbler display object:
**  extern "C" IDisplay* IDISPLAY_MAKE_SYMBOL(int map_width, int map_height);
**
**  If the display module cannot handler these parameters, it can raise a
**  std::invalid_argument exception with a human-readable error message.
**  Otherwise, a Display object pointer implementing IDisplay must be returned.
**
**  On successful initialization, update_game will then be called on every
**  game event. The display must then use the interface/subinterfaces of Game
**  (like Snake and Map) in it to represent the game state to the player.
**
**  The display must raise any type of exception on critical errors.
**  For non-critical errors, a warning error may be printed on stderr.
**
**  Cleanup instructions are to be implemented in the display destructor.
*/

#include "Direction.hpp"
#include "Game.hpp"

class IDisplay
{
    public:
        virtual ~IDisplay() {}

        /*
        **  Get the new snake direction and return true.
        **  Return false to stop the game, true otherwise.
        */
        virtual bool get_input(Direction& snake_direction) = 0;

        /*
        **  Display the game using the game object interface.
        */
        virtual void display(Game const& game) = 0;
};

#endif
