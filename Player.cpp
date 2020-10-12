#include "Player.h"
#include <ncurses.h>
#include <iostream>
#include <vector>

// gets user input
// parse input

void Player::input() {

    // apply momentum based on keys
    for (auto key : keys) {
	    switch (key) {
			case 'W':
			case KEY_UP:
			    if (grounded()) {
					setYMomentum(-3);
					setGrounded(false); // object moving up
			    }
			    break;
			case 'A':
			case KEY_LEFT:
				setXMomentum(-1);
			    break;
			case 'D':
			case KEY_RIGHT:
				setXMomentum(1);
			    break;
		    }
	}

    //while (getch() != ERR); // clear buffer
}

// add user input to tick method
void Player::tick() {
	PhysicsObject::tick();
	input();
}

// set keys
void Player::setKeys(std::vector <int> newKeys) {
	keys = newKeys;
} 

// we only have one player, so this should never get called or do anything
bool Player::check_collision(Player *p) { return false; }
bool Player::collide(Player *p) { return false; }
