#include "RenderedObject.h"
#include <iostream>

RenderedObject::RenderedObject(char sprite, int x, int y)
    : sprite(sprite)
    , x(x)
    , y(y)
{}

// TODO - ncurses
void RenderedObject::render() {
    std::cout << "object " << sprite
              << " at (" << x << ", " << y << ")" << std::endl;
}

