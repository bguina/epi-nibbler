//
// Made by benoit guina
// Login   <guina_b@epitech.net>
//

#ifndef HPP_SNAKE
#define HPP_SNAKE

#include <deque>

#include "Position.hpp"
#include "Direction.hpp"

typedef std::deque<Position> SnakePosition;

class Snake
{
    public:
        static const unsigned int default_length = 4;

        Snake(int x, int y, unsigned int length=default_length, Direction::EDirection direction=Direction::DIRECTION_UP);

        // Getters
        SnakePosition::const_iterator begin() const;
        SnakePosition::const_iterator end() const;
        Direction const& direction() const;
        bool is_occupied(int x, int y) const;
        unsigned int length() const;

        // Modifiers
        bool turn(Direction::EDirection dir);
        bool move(bool grow);

    protected:
        SnakePosition m_pos;
        Direction m_dir;
};

#endif
