#include "PhysicsObject.h"
#include <ncurses.h>
#include <unistd.h>


void PhysicsObject::tick() {
    // check if physics should be applied and object rendered again this tick
    incrementTick();
    if (getTick() >= getTickLimit()) {
        resetTick();
        // hold old location
        if (!grounded() || getXMomentum() != 0) {
            oldY = y;
            oldX = x;
        }

        // apply gravity only if not moving up
        if (getYMomentum() >= 0 && !grounded()) {
            //usleep(1000000);
            y = y + 1;
        }  else if (y > 0 && getYMomentum() != 0) {
            // decrement momentum and move up
            setYMomentum(getYMomentum() + 1);
            y--;
        }

        // screen size
        int maxY, maxX;
        getmaxyx(stdscr, maxY, maxX);

        // apply any left and right momentum
        if (getXMomentum() > 0 && x < maxX) {
            x++;
            setXMomentum(getXMomentum() - 1);
        } else if (getXMomentum() < 0 && x > 0) {
            x--;
            setXMomentum(getXMomentum() + 1);
        }

        render();
    }

}

PhysicsObject::PhysicsObject(char sprite, int x, int y)
    : CollisionObject::CollisionObject(sprite, x, y)
    , tickCount(0)
    , tickLimit(30)
    , yMomentum(0)
    , xMomentum(0)
{}

// render object and remove from previous location
void PhysicsObject::render() {
    mvprintw(oldY, oldX, " ");
    SpriteObject::render();
}

// increment tick count that tracks if this object is to be updated
void PhysicsObject::incrementTick() {
    tickCount++;
}

// get tick count
int PhysicsObject::getTick() {
    return tickCount;
}

// point at which to render object
int PhysicsObject::getTickLimit() {
    return tickLimit;
}


// reset tick count
void PhysicsObject::resetTick() {
    tickCount = 0;
}

// denote object as grounded or ungrounded
void PhysicsObject::setGrounded(bool grounded) {
    onGround = grounded;
}

// check if object grounded
bool PhysicsObject::grounded() {
    return onGround;
}

// get and set momentum
int PhysicsObject::getYMomentum() {
    return yMomentum;
}

void PhysicsObject::setYMomentum(int val) {
    yMomentum = val;
}

int PhysicsObject::getXMomentum() {
    return xMomentum;
}

void PhysicsObject::setXMomentum(int val) {
    xMomentum = val;
}