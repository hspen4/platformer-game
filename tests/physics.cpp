#include "../PhysicsObject.h"
#include "assert.h"

#include <iostream>

void physics() {
    int last_x = 10;
    int last_y = 10;
    PhysicsObject a('@', last_x, last_y);

    for (int i = 0; i < 120; i++) a.tick();
    assertm(a.get_y() > last_y, "gravity");

    a.set_dx(5);
    for (int i = 0; i < 120; i++) a.tick();
    assertm(a.get_x() > last_x, "momentum");

    float last_dx = a.get_dx();
    a.set_grounded(true);
    for (int i = 0; i < 120; i++) a.tick();
    assertm(a.get_dx() < last_dx, "friction");
}
