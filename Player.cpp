#include "Player.h"
#include <ncurses.h>
#include <iostream>

// gets user input
void Player::input() {
    int key = getch(); // get non-blocking input if available
    // apply momentum based on keys
    switch (key) {
	case 'W':
	case KEY_UP:
	    if (yMomentum == 0 && y > 8) {
		yMomentum = -3;
	    }
	    break;
	case 'A':
	case KEY_LEFT:
	    xMomentum--;
	    break;
	case 'D':
	case KEY_RIGHT:
	    xMomentum++;
	    break;
    }

    while (getch() != ERR); // clear buffer
}

// add user input to tick method
void Player::tick() {
	PhysicsObject::tick();
	input();
}

// we only have one player, so this should never get called or do anything
bool Player::check_collision(Player *p) { return false; }
bool Player::collide(Player *p) { return false; }
