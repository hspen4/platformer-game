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

int SpriteObject::get_x() { return x; }
int SpriteObject::get_y() { return y; }

void SpriteObject::set_x(int _x) { x = _x; }
void SpriteObject::set_y(int _y) { y = _y; }
