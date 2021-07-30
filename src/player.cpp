#include "player.hpp"


Coord Player::getMoveTo(int key)
{
    Coord ret = p;
    switch (Key(key)) {
        case Key::up:
            ret.x--;
            break;

        case Key::down:
            ret.x++;
            break;

        case Key::left:
            ret.y--;
            break;

        case Key::right:
            ret.y++;
            break;
    }
    return ret;
}
