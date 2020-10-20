#ifndef ENEMYJUMPER_H
#define ENEMYJUMPER_H

#include "Enemy.h"
#include "TickCounter.h"

class EnemyJumper : public Enemy {
public:
    EnemyJumper(char sprite, double x, double y);
    void tick() override;
private:
    TickCounter jump_timer;
};

#endif

