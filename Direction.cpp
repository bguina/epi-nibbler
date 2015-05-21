//
// Made by benoit guina
// Login   <guina_b@epitech.net>
//

#include <iostream>



#include <stdexcept>

#include "IDisplay.hpp"
#include "Direction.hpp"

Direction::Direction(EDirection direction)
    : m_direction(DIRECTION_UP)
{
    set(direction);
}

Direction::EDirection Direction::opposite() const
{
    switch (m_direction)
    {
        case DIRECTION_LEFT:
            return DIRECTION_RIGHT;
        case DIRECTION_RIGHT:
            return DIRECTION_LEFT;
        case DIRECTION_UP:
            return DIRECTION_DOWN;
        default: ;
    }
    return DIRECTION_UP;
}

void Direction::set(EDirection direction)
{
    if (direction < 0 || direction >= DIRECTION_TOTAL)
        throw std::logic_error("Direction enum value not in range");
    m_direction = direction;
}

Direction::EDirection Direction::get() const
{
    return (m_direction);
}

void Direction::move(int& x, int& y, int const& d) const
{
    switch (m_direction)
    {
        case DIRECTION_LEFT:
            x -= d;
            break;
        case DIRECTION_RIGHT:
            x += d;
            break;
        case DIRECTION_UP:
            y -= d;
            break;
        case DIRECTION_DOWN:
            y += d;
            break;
        default: ;
    }
}
