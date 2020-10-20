#include "EnemyWalker.h"
#include "GameState.h"
#include "PhysicsObject.h"
#include "Player.h"
#include "TickCounter.h"
#include <cstdlib>

extern int max_x, max_y;

EnemyWalker::EnemyWalker(char sprite, double x, double y)
    : Enemy(sprite, x, y)
    , movement_timer(30)
    , movement_direction(-1)
{}

void EnemyWalker::tick() {
    PhysicsObject::tick();
    if (!grounded()) {
        // we've walked off an edge - reverse direction
        movement_direction *= -1;
        set_x(get_x() + movement_direction);
    }
    if (movement_timer.check()) {
        old_x = get_x();
        set_x(get_x() + movement_direction);
    }
}

