#include "SpriteObject.h"
#include <ncurses.h>

// object representing all single character sprites that need to be rendered

// pass location to spawn
SpriteObject::SpriteObject(char sprite, double x, double y)
    : x(x)
    , y(y)
{

    this->sprite[0] = sprite;
    this->sprite[1] = '\0';
}

// called when object spawned or moved
void SpriteObject::render() {
    mvprintw(y, x, sprite);
}

// getters and setters
double SpriteObject::get_x() { return x; }
double SpriteObject::get_y() { return y; }

int SpriteObject::get_render_x() { return static_cast<int>(x); }
int SpriteObject::get_render_y() { return static_cast<int>(y); }

void SpriteObject::set_x(double _x) { x = _x; }
void SpriteObject::set_y(double _y) { y = _y; }
