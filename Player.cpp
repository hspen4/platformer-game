#include "Player.h"
#include "GameState.h"
#include <ncurses.h>
#include <iostream>
#include <vector>

extern int max_x, max_y;

// ctor

Player::Player(char sprite, float x, float y)
    : PhysicsObject::PhysicsObject(sprite, x, y)
    , score(0)
    , cur_state(GameState::Playing)
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
					set_dy(-8);
			    }
			    break;
			case 'A':
			case KEY_LEFT:
				set_dx(-10);
			    break;
			case 'D':
			case KEY_RIGHT:
				set_dx(10);
			    break;
		    }
	}
}

// add user input to tick method
void Player::tick() {
	input();
	PhysicsObject::tick();
	// re-print score
	for(int i = 0; i <= max_x; i++) {
		mvprintw(0,i," ");
	}
	mvprintw(0,0,"Score: %d", get_score());

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
GameState Player::get_state() { return cur_state; }
void Player::set_state(GameState state) { cur_state = state; }
