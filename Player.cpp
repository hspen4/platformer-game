#include "Player.h"
#include <ncurses.h>
#include <iostream>
#include <vector>

// gets user input
void Player::input() {
	std::vector <int> keys;
	int key;
	while ((key = getch()) != ERR) {
		keys.push_back(key); // get non-blocking input if available
	}

    // apply momentum based on keys
    for (auto key : keys) {
	    switch (key) {
			case 'W':
			case KEY_UP:
			    if (yMomentum == 0 && y > 8) {
				yMomentum = -3;
			    }
			    break;
			case 'A':
			case KEY_LEFT:
				xMomentum = -1;
			    break;
			case 'D':
			case KEY_RIGHT:
				xMomentum = 1;
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

// we only have one player, so this should never get called or do anything
bool Player::check_collision(Player *p) { return false; }
bool Player::collide(Player *p) { return false; }
