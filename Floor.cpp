#include "Floor.h"
#include <ncurses.h>

// floors are special case objects that inherit directly from rendered object

// ctor
Floor::Floor(int left_x, int right_x, int y)
    : left_x(left_x)
    , right_x(right_x)
    , y(y)
{}

// check if user is inside floor or directly above it
void Floor::collide(PhysicsObject *obj) {
	// check user is within range of platform
    if (obj->get_render_x() >= left_x &&
        obj->get_render_x() <= right_x
    ) {
        if (obj->get_render_y() == y) {
        // user is inside floor
            if (obj->get_dy() >= 0) {
                // falling object - push it up and reset momentum
                obj->set_y(obj->get_y() - 1);
                obj->set_dy(0);
                obj->set_grounded(true);
            }
        // check if user is directly above floor, making them grounded
        } else if (obj->get_render_y() == y - 1) {
            obj->set_grounded(true);
        }
    }
}

// render floor across multiple tiles
void Floor::render() {
    for (int i = left_x; i <= right_x; i++) {
        mvprintw(y, i, "#");
    }
}
