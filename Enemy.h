#ifndef ENEMY_H
#define ENEMY_H

#include "PhysicsObject.h"
#include "TickCounter.h"

// enemies move from side to side and kill the player if they collide
class Enemy : public PhysicsObject {
public:
    Enemy(char sprite, double x, double y);
    void tick() override;
    bool collide(Player *p) override;

private:
    TickCounter movement_timer;
    int movement_direction;
    int movement_steps;
};

#endif
