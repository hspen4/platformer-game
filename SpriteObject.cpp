#include "SpriteObject.h"
#include <ncurses.h>

SpriteObject::SpriteObject(char sprite, int x, int y)
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

int SpriteObject::get_x() { return x; }
int SpriteObject::get_y() { return y; }

void SpriteObject::set_x(int _x) { x = _x; }
void SpriteObject::set_y(int _y) { y = _y; }
