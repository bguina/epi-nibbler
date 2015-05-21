//
// Made by benoit guina
// Login   <guina_b@epitech.net>
//

#include <algorithm>

#include "Snake.hpp"

Snake::Snake(int x, int y, unsigned int length, Direction::EDirection dir)
    : m_dir(dir)
{
    m_pos.push_front(Position(x, y));
    for (unsigned int i = 1; i < length; i++)
    {
        m_pos.push_back(m_pos.back());
        m_dir.move(m_pos.back().first, m_pos.back().second, -1);
    }
}

SnakePosition::const_iterator Snake::begin() const
{
    return (m_pos.begin());
}

SnakePosition::const_iterator Snake::end() const
{
    return (m_pos.end());
}

Direction const& Snake::direction() const
{
    return (m_dir);
}

bool Snake::is_occupied(int x, int y) const
{
    if (std::find(m_pos.begin(), m_pos.end(), Position(x, y)) == m_pos.end())
        return (false);
    return (true);
}

unsigned int Snake::length() const
{
    return (m_pos.size());
}

bool Snake::turn(Direction::EDirection dir)
{
    if (m_dir.opposite() == dir)
        return (false);
    m_dir = dir;
    return (true);
}

bool Snake::move(bool grow)
{
    m_pos.push_front(m_pos.front());
    m_dir.move(m_pos.front().first, m_pos.front().second);
    if (!grow)
        m_pos.pop_back();
    if (std::find(m_pos.begin() + 1, m_pos.end(), m_pos.front()) != m_pos.end())
        return (false);
    return (true);
}

