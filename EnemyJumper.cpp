#include "EnemyJumper.h"
#include "PhysicsObject.h"

// enemy object that jumps

EnemyJumper::EnemyJumper(char sprite, double x, double y)
    : Enemy(sprite, x, y)
    , jump_timer(60) // jump every 60 ticks
{}

void EnemyJumper::tick() {
    PhysicsObject::tick();

    // jump on tick, if not grounded
    if (grounded()) {
        if (jump_timer.check()) {
            set_dy(-10);
        }
    }
}
