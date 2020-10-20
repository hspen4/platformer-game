#include "EnemyJumper.h"
#include "PhysicsObject.h"

EnemyJumper::EnemyJumper(char sprite, double x, double y)
    : Enemy(sprite, x, y)
    , jump_timer(60)
{}

void EnemyJumper::tick() {
    PhysicsObject::tick();

    if (grounded()) {
        if (jump_timer.check()) {
            set_dy(-10);
        }
    }
}
