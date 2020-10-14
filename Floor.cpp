#include "Floor.h"
#include <ncurses.h>

Floor::Floor(int left_x, int right_x, int y)
    : left_x(left_x)
    , right_x(right_x)
    , y(y)
{}

void Floor::collide(PhysicsObject *obj) {
    if (obj->get_y() == y) {
        if (obj->get_x() >= left_x && obj->get_x() <= right_x) {
            // the object's inside the floor, make sure it has upwards momentum
            if (obj->get_momentum_y() >= 0) {
                obj->set_momentum_y(-1);
            }
        }
    } else if (obj->get_y() == (y - 1) && obj->get_momentum_y() == 0) {
        if (obj->get_x() >= left_x && obj->get_x() <= right_x) {
            // object is grounded, set status
            obj->set_grounded(true);
        }
    }
    return;
}

void Floor::render() {
    for (int i = left_x; i <= right_x; i++) {
        mvprintw(y, i, "#");
    }
}
