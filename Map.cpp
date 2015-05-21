//
// Made by benoit guina
// Login   <guina_b@epitech.net>
//

#include <stdexcept>
#include <algorithm>

#include "Map.hpp"

#include <iostream>

Map::Map(int width, int height)
    : m_width(width), m_height(height)
{
    if (m_width < min_width || m_height < min_height)
        throw std::invalid_argument("the map is too small");
}

int Map::width() const
{
    return (m_width);
}

int Map::height() const
{
    return (m_height);
}

bool Map::is_wall(int x, int y) const
{
    return (!(x >= 0 && x < m_width && y >= 0 && y < m_height));
}

bool Map::is_food(int x, int y) const
{
    return (std::find(m_food.begin(), m_food.end(), Position(x, y)) != m_food.end());
}

FoodPosition::const_iterator Map::food_begin() const
{
    return (m_food.begin());
}

FoodPosition::const_iterator Map::food_end() const
{
    return (m_food.end());
}

bool Map::put_food(int x, int y)
{
    if (is_wall(x, y) || is_food(x, y))
        return (false);
    m_food.push_front(Position(x, y));
    return (true);
}

bool Map::remove_food(int x, int y)
{
    FoodPosition::iterator it(std::find(m_food.begin(), m_food.end(), Position(x, y)));

    if (it == m_food.end())
        return (false);
    m_food.erase(it);
    return (true);
}
