//
// Made by benoit guina
// Login   <guina_b@epitech.net>
//

#ifndef HPP_PLAYER
#define HPP_PLAYER

#include "IController.hpp"

class Player : public IController
{
    public:
        virtual Direction play(Snake const& snake, Game const& game);
        
    protected:
    
};

#endif
