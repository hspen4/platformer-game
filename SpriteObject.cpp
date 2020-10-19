#include "SpriteObject.h"
#include <ncurses.h>

SpriteObject::SpriteObject(char sprite, float x, float y)
    : x(x)
    , y(y)
{

	this->sprite[0] = sprite;
	this->sprite[1] = '\0';

}

// TODO - ncurses
void SpriteObject::render() {
	mvprintw(y, x, sprite);
}

float SpriteObject::get_x() { return x; }
float SpriteObject::get_y() { return y; }

int SpriteObject::get_render_x() { return static_cast<int>(x); }
int SpriteObject::get_render_y() { return static_cast<int>(y); }

void SpriteObject::set_x(float _x) { x = _x; }
void SpriteObject::set_y(float _y) { y = _y; }
