#include "SpriteObject.h"
#include <iostream>

SpriteObject::SpriteObject(char sprite, int x, int y)
    : sprite(sprite)
    , x(x)
    , y(y)
{}

// TODO - ncurses
void SpriteObject::render() {
    std::cout << "object " << sprite
              << " at (" << x << ", " << y << ")" << std::endl;
}

