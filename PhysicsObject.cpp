#include "PhysicsObject.h"
#include <ncurses.h>
#include <unistd.h>

// FIXME this is pretty terrible
extern int max_x, max_y;

void PhysicsObject::tick() {
    // check if physics should be applied and object rendered again this tick
    increment_tick();
    if (get_tick() >= get_tick_limit()) {
        reset_tick();
        // hold old location
        if (!grounded() || get_momentum_x() != 0) {
            old_y = y;
            old_x = x;
        }

        // apply gravity only if not moving up
        if (get_momentum_y() >= 0 && !grounded()) {
            //usleep(1000000);
            y = y + 1;
        }  else if (y > 0 && get_momentum_y() != 0) {
            // decrement momentum and move up
            set_momentum_y(get_momentum_y() + 1);
            y--;
        }

        // apply any left and right momentum
        if (get_momentum_x() > 0 && x < max_x) {
            x++;
            set_momentum_x(get_momentum_x() - 1);
        } else if (get_momentum_x() < 0 && x > 0) {
            x--;
            set_momentum_x(get_momentum_x() + 1);
        }
    }
}

PhysicsObject::PhysicsObject(char sprite, int x, int y)
    : CollisionObject::CollisionObject(sprite, x, y)
    , tick_count(0)
    , tick_limit(30)
    , momentum_y(0)
    , momentum_x(0)
    , on_ground(false)
{}

// render object and remove from previous location
void PhysicsObject::render() {
    mvprintw(old_y, old_x, " ");
    SpriteObject::render();
}

// increment tick count that tracks if this object is to be updated
void PhysicsObject::increment_tick() { tick_count++; }
// get tick count
int PhysicsObject::get_tick() { return tick_count; }
// point at which to render object
int PhysicsObject::get_tick_limit() { return tick_limit; }
// reset tick count
void PhysicsObject::reset_tick() { tick_count = 0; }

// denote object as grounded or ungrounded
void PhysicsObject::set_grounded(bool grounded) { on_ground = grounded; }
// check if object grounded
bool PhysicsObject::grounded() { return on_ground; }

// get and set momentum
int PhysicsObject::get_momentum_y() { return momentum_y; }
void PhysicsObject::set_momentum_y(int val) { momentum_y = val; }
int PhysicsObject::get_momentum_x() { return momentum_x; }
void PhysicsObject::set_momentum_x(int val) { momentum_x = val; }
