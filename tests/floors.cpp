#include "../PhysicsObject.h"
#include "../Floor.h"
#include "assert.h"
#include <iostream>

void floors() {
    Floor f(0, 10, 5);
    PhysicsObject p('@', 9, 2); // two tiles above the floor


    // after one tick, there should be a 1 tile gap between p and the floor
    for (int i = 0; i <= p.y_tick.frequency; i++) {
        p.tick();
        f.collide(&p);
    }
    assertm(p.get_y() == 3, "first fall tick");
    assertm(p.grounded() == false, "first fall tick");

    // after the second tick, p should have hit the floor
    for (int i = 0; i <= p.y_tick.frequency; i++) {
        p.tick();
        f.collide(&p);
    }
    assertm(p.get_y() == 4, "second fall tick");

    // after the third, p should still be on the floor
    for (int i = 0; i <= p.y_tick.frequency; i++) {
        p.tick();
        f.collide(&p);
    }
    assertm(p.grounded() == true, "third fall tick");
    assertm(p.get_y() == 4, "third fall tick");

    // move p inside the floor (this happens if you jump from below)
    // the floor should push p upwards
    p.set_y(5);
    f.collide(&p);
    assertm(p.get_momentum_y() <= 0, "pushed from inside floor");

    // move p to the right, they should start falling
    p.set_x(15);
    for (int i = 0; i < 3; i++) {
        for (int i = 0; i <= p.y_tick.frequency; i++) {
            p.tick();
            f.collide(&p);
        }
        //std::cout << p.get_x() << " " << p.get_y() << " " << p.grounded() << " " << p.get_momentum_y() << std::endl;
    }
    assertm(p.get_y() > 4, "falling after walking off a platform");
    assertm(p.grounded() == false, "falling after walking off a platform");
}
