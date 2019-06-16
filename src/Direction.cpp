#include "Direction.hpp"

Direction charToDirection(char c){
    switch(c){
        case 'w': return Direction::UP;
        case 's': return Direction::DOWN;
        case 'a': return Direction::LEFT;
        case 'd': return Direction::RIGHT;
        default: throw;
    }
}