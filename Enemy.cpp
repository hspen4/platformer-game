#include "Enemy.h"
#include "Player.h"

bool Enemy::collide(Player *p) {
    // respawn player
    p->respawn();
    return false;
}
