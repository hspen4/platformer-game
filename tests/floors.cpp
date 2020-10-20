#include "../PhysicsObject.h"
#include "../Floor.h"
#include "harness.h"
#include <iostream>

void floors(Harness *assert) {
    assert->context("floors");

    Floor f(0, 10, 5);
    PhysicsObject p('@', 9, 2); // two tiles above the floor

    for (int i = 0; i <= 600; i++) {
        p.tick();
        f.collide(&p);
    }
    assert->eq(p.get_render_y(), 4, "position on floor");
    assert->eq(p.grounded(), true, "grounded on floor");

    // move p to the right, they should start falling
    p.set_dy(-1);
    p.set_x(15);
    for (int i = 0; i <= 600; i++) {
        p.tick();
        f.collide(&p);
    }
    assert->gt(p.get_y(), 4.0, "position falling after walking off a platform");
    assert->eq(p.grounded(), false, "grounded falling after walking off a platform");
}
