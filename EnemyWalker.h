#ifndef ENEMYWALKER_H
#define ENEMYWALKER_H

#include "Enemy.h"
#include "TickCounter.h"

// enemy that moves from side to side along platforms
class EnemyWalker : public Enemy {
public:
    EnemyWalker(char sprite, double x, double y);
    void tick() override;

private:
    TickCounter movement_timer; // track when to move across
    int movement_direction;
};

#endif
