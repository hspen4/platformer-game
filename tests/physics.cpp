#include "../PhysicsObject.h"
#include "harness.h"

#include <iostream>

void physics(Harness *assert) {
    assert->context("physics");

    double last_x = 10;
    double last_y = 10;
    PhysicsObject a('@', last_x, last_y);

    for (int i = 0; i < 120; i++) a.tick();
    assert->gt(a.get_y(), last_y, "gravity");

    a.set_dx(5);
    for (int i = 0; i < 120; i++) a.tick();
    assert->gt(a.get_x(),  last_x, "momentum");

    double last_dx = a.get_dx();
    a.set_grounded(false);
    for (int i = 0; i < 120; i++) a.tick();
    assert->eq(a.get_dx(), last_dx, "no friction in air");

    a.set_grounded(true);
    for (int i = 0; i < 120; i++) a.tick();
    assert->lt(a.get_dx(), last_dx, "friction");
}
