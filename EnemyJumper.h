#ifndef ENEMYJUMPER_H
#define ENEMYJUMPER_H

#include "Enemy.h"
#include "TickCounter.h"

// enemy class that moves up and down

class EnemyJumper : public Enemy {
public:
    EnemyJumper(char sprite, double x, double y);
    void tick() override;
private:
    TickCounter jump_timer; // track ticks
};

#endif

