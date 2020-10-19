#include "../PhysicsObject.h"
#include "../Floor.h"
#include "assert.h"
#include <iostream>

void floors() {
    Floor f(0, 10, 5);
    PhysicsObject p('@', 9, 2); // two tiles above the floor

    for (int i = 0; i <= 600; i++) {
        p.tick();
        f.collide(&p);
    }
    assertm(p.get_render_y() == 4, "landed on floor");
    assertm(p.grounded() == true, "landed on floor");
    
    // move p to the right, they should start falling
    p.set_dy(-1);
    p.set_x(15);
    for (int i = 0; i <= 600; i++) {
        p.tick();
        f.collide(&p);
    }
    assertm(p.get_y() > 4, "falling after walking off a platform");
    assertm(p.grounded() == false, "falling after walking off a platform");
}
