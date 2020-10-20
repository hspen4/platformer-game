#include "PhysicsObject.h"
#include "TickCounter.h"
#include <algorithm>
#include <ncurses.h>
#include <unistd.h>

#include <iostream>

// FIXME this is pretty terrible
extern int max_x, max_y;

const double tick_dt = 0.016;
const double gravity = 0.15;

void PhysicsObject::tick() {
    old_x = x;
    old_y = y;
    if (dy < 0) set_grounded(false);

    // you can only move at most 1 tile per tick
    x += std::min(dx * tick_dt, 1.0);
    y += std::min(dy * tick_dt, 1.0);

    // gravity
    dy += gravity; // 1/60 * 9

    // friction
    if (on_ground) {
        dx *= 0.7;
    }
}

PhysicsObject::PhysicsObject(char sprite, float x, float y)
    : CollisionObject::CollisionObject(sprite, x, y)
    , dy(0)
    , dx(0)
    , on_ground(false)
    , orig_x(x)
    , orig_y(y)
{}

// render object and remove from previous location
void PhysicsObject::render() {
    if (old_y != y || old_x != x) mvprintw(old_y, old_x, " ");
    SpriteObject::render();
}

bool PhysicsObject::collide(Player *p) { return true; }

void PhysicsObject::set_dx(double _dx) { dx = _dx; }
void PhysicsObject::set_dy(double _dy) { dy = _dy; }

double PhysicsObject::get_dx() { return dx; }
double PhysicsObject::get_dy() { return dy; }

// denote object as grounded or ungrounded
void PhysicsObject::set_grounded(bool grounded) { on_ground = grounded; }
// check if object grounded
bool PhysicsObject::grounded() { return on_ground; }
