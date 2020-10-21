#include "Player.h"
#include "GameState.h"
#include <iostream>
#include <ncurses.h>
#include <vector>
#include <algorithm>

extern int max_x, max_y;

// class representing the player's sprite

// ctor
Player::Player(char sprite, float x, float y)
    : PhysicsObject::PhysicsObject(sprite, x, y)
    , score(201)
    , cur_state(GameState::Playing)
{}

// gets user input
// parse input
void Player::input() {
    // apply momentum based on keys
    for (auto key : keys) {
        switch (key) {
        case 'W':
        case 'w':
        case ' ':
        case KEY_UP:
            if (grounded()) {
                set_dy(-8);
            }
            break;
        case 'a':
        case 'A':
        case KEY_LEFT:
            set_dx(-10);
            break;
        case 'd':
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
    if (score > 0) {
        score-=0.02;
    }
    // check if player has fallen through the floor and died
    if (y >= max_y) {
        respawn();
    }
    // re-print score
    for (int i = 0; i <= max_x; i++) {
        mvprintw(0, i, " ");
    }
    mvprintw(0, 0, "Score: %d", (int)get_score());
}

// respawn at original location on death
void Player::respawn() {
    set_score(get_score() - 50);
    if (get_score() < 0) {
        set_score(0);
    }
    set_dx(0);
    set_dy(0);
    y = orig_y;
    x = orig_x;
}
//
// set keys
void Player::set_keys(std::vector<int> newKeys) { keys = newKeys; }

// we only have one player, so this should never get called or do anything
bool Player::check_collision(Player *p) { return false; }
bool Player::collide(Player *p) { return false; }

// getters and setters
float Player::get_score() { return score; }
void Player::set_score(float score) { this->score = score; }
GameState Player::get_state() { return cur_state; }
void Player::set_state(GameState state) { cur_state = state; }
