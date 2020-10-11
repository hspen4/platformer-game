#include "PhysicsObject.h"
#include <ncurses.h>
#include <unistd.h>


void PhysicsObject::tick() {
	// check if physics should be applied and object rendered again this tick
	incrementTick();
	if (getTick() >= getTickLimit()) {
		resetTick();
		// hold old location
		if (yMomentum != 0 || xMomentum != 0 || y != 9) {
			oldY = y;
			oldX = x;
		}

		// apply gravity only if not moving up
	    if (yMomentum >= 0 && y<9) {
	    	//usleep(1000000);
	    	y = y + 1;
	    }  else if (y > 0 && yMomentum != 0) {
	    	// decrement momentum and move up
	    	yMomentum++;
	    	y--;
	    }

	 	// apply any left and right momentum   
	 	if (xMomentum > 0) {
	 		x++;
	 		xMomentum--;
	 	} else if (xMomentum < 0) {
	 		x--;
	 		xMomentum++;
	 	}

	 	render();
	 }

}

PhysicsObject::PhysicsObject(char sprite, int x, int y) : CollisionObject::CollisionObject(sprite, x, y), yMomentum(0), xMomentum(0), tickCount(0), tickLimit(3)
{

}

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