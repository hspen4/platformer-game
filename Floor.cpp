#include "Floor.h"
#include <iostream>

Floor::Floor(int left_x, int right_x, int y)
    : left_x(left_x)
    , right_x(right_x)
    , y(y)
{}

void Floor::collide(PhysicsObject *obj) {
    if (obj->get_y() != y) return;
    if (obj->get_x() < left_x || obj->get_x() > right_x) return;

    // the object's inside the floor, push it upwards
    int new_y = obj->get_y() + 1;
    obj->set_y(new_y);
}

void Floor::render() {
    std::cout << "floor from " << left_x << " to " << right_x;
    std::cout << " at y " << y << std::endl;
}
