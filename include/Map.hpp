//
// Made by benoit guina
// Login   <guina_b@epitech.net>
//

#ifndef HPP_MAP
#define HPP_MAP

#include <list>

#include "Position.hpp"

typedef std::list<Position> FoodPosition;

class Map
{
    public:
        static const int min_width = 4;
        static const int min_height = 4;

        Map(int width, int height);

        // Getters
        int width() const;
        int height() const;

        bool is_wall(int x, int y) const;
        bool is_food(int x, int y) const;

        FoodPosition::const_iterator food_begin() const;
        FoodPosition::const_iterator food_end() const;
        
        // Modifiers
        bool put_food(int x, int y);
        bool remove_food(int x, int y);

    protected:
        int const m_width;
        int const m_height;
        FoodPosition m_food;
};

#endif
