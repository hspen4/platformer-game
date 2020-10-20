#include "Enemy.h"
#include "GameState.h"
#include "PhysicsObject.h"
#include "Player.h"
#include "TickCounter.h"
#include <cstdlib>

extern int max_x, max_y;

Enemy::Enemy(char sprite, double x, double y)
    : PhysicsObject(sprite, x, y)
    , movement_timer(30)
    , movement_direction(-1)
    , movement_steps(15)
{}

void Enemy::tick() {
    PhysicsObject::tick();
    if (movement_timer.check()) {
        old_x = get_x();
        if (!movement_steps) {
            // set steps to 5-10 randomly
            movement_steps = 5 + (std::rand() % 5);
            // move the other direction
            movement_direction *= -1;
        }
        // stop the enemy from walking off the edge of the screen
        if ((get_x() + movement_direction) >= max_x) movement_direction = -1;
        if ((get_x() + movement_direction) <= 0) movement_direction = 1;

        set_x(get_x() + movement_direction);
        movement_steps--;
    }
}

bool Enemy::collide(Player *p) {
    // respawn player
    p->respawn();
    return false;
}
