#include "../PhysicsObject.h"
#include "assert.h"

void physics() {
    int last_x = 10;
    int last_y = 10;
    PhysicsObject a('@', last_x, last_y);

    for (int i = 0; i <= a.get_tick_limit(); i++) a.tick();
    assertm(a.get_y() > last_y, "gravity");
    assertm(a.get_x() == last_x, "gravity");

    last_y = a.get_y();
    for (int i = 0; i <= a.get_tick_limit(); i++) a.tick();
    assertm(a.get_y() > last_y, "gravity");
    assertm(a.get_x() == last_x, "gravity");

    a.set_momentum_x(1);
    for (int i = 0; i <= a.get_tick_limit(); i++) a.tick();
    assertm(a.get_x() > last_x, "momentum");

    last_x = a.get_x();
    for (int i = 0; i <= a.get_tick_limit(); i++) a.tick();
    assertm(a.get_x() == last_x, "momentum decay");
    assertm(a.get_momentum_x() == 0, "momentum decay");
}
