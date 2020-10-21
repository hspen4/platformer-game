#include "Enemy.h"
#include "Player.h"

// base class for all enemies that must be avoided

bool Enemy::collide(Player *p) {
    // respawn player
    p->respawn();
    return false;
}
