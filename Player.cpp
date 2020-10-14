#include "Player.h"
#include <ncurses.h>
#include <iostream>
#include <vector>

// ctor

Player::Player(char sprite, int x, int y)
    : PhysicsObject::PhysicsObject(sprite, x, y)
    , score(0)
    , playing(true)
{}

// gets user input
// parse input

void Player::input() {
    // apply momentum based on keys
    for (auto key : keys) {
	    switch (key) {
			case 'W':
			case KEY_UP:
			    if (grounded()) {
					set_momentum_y(-3);
			    }
			    break;
			case 'A':
			case KEY_LEFT:
				set_momentum_x(-1);
			    break;
			case 'D':
			case KEY_RIGHT:
				set_momentum_x(1);
			    break;
		    }
	}

}

// add user input to tick method
void Player::tick() {
	input();
	PhysicsObject::tick();
}

// set keys
void Player::set_keys(std::vector <int> newKeys) {
	keys = newKeys;
} 

// we only have one player, so this should never get called or do anything
bool Player::check_collision(Player *p) { return false; }
bool Player::collide(Player *p) { return false; }


// getters and setters
int Player::get_score() { return score; }
void Player::set_score(int score) { this->score = score; }
bool Player::get_playing() { return playing; }
void Player::set_playing(bool playing) { this->playing = playing; }