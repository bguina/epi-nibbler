//
// Made by benoit guina
// Login   <guina_b@epitech.net>
//

#ifndef HPP_DIRECTION
#define HPP_DIRECTION

#include <utility>

class Direction
{
    public:
        typedef enum EDirection
        {
            DIRECTION_LEFT,
            DIRECTION_RIGHT,
            DIRECTION_UP,
            DIRECTION_DOWN,
            DIRECTION_TOTAL
        } EDirection;

        Direction(EDirection direction=DIRECTION_UP);

        Direction::EDirection opposite() const;

        void set(EDirection direction);
        Direction::EDirection get() const;

        void move(int& x, int& y, int const& d=1) const;
  
  bool operator==(EDirection direction) const;
  bool operator!=(EDirection direction) const;
  
public:
  EDirection m_direction;
};

//std::pair<int, int>& operator+(std::pair<int, int>& position, Direction const& direction);

#endif
