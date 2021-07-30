#ifndef PLAYER_HPP
#define PLAYER_HPP


#include "coord.hpp"


class Player
{
public:
    enum class Key
    {
        up = 'w',
        down = 's',
        left = 'a',
        right = 'd'
    };

    Coord p;

    Player(Coord p) : p(p) {}
    Coord getMoveTo(int key);
};


#endif
