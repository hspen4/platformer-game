#include "Floor.h"
#include <ncurses.h>

Floor::Floor(int left_x, int right_x, int y)
    : left_x(left_x)
    , right_x(right_x)
    , y(y)
{}

void Floor::collide(PhysicsObject *obj) {
    if (obj->get_render_y() == y
        && obj->get_render_x() >= left_x && obj->get_render_x() <= right_x
    ) {
        if (obj->get_dy() >= 0) {
            // falling object - push it up and reset momentum
            obj->set_y(obj->get_y() - 1);
            obj->set_dy(0);
            obj->set_grounded(true);
        }
    }
}

void Floor::render() {
    for (int i = left_x; i <= right_x; i++) {
        mvprintw(y, i, "#");
    }
}
