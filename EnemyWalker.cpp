#include "EnemyWalker.h"
#include "GameState.h"
#include "PhysicsObject.h"
#include "Player.h"
#include "TickCounter.h"
#include <cstdlib>

extern int max_x, max_y;

// enemy type that walks across platforms

EnemyWalker::EnemyWalker(char sprite, double x, double y)
    : Enemy(sprite, x, y)
    , movement_timer(30) // move every 30 ticks
    , movement_direction(-1) // tracks whether we are moving left or right
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

