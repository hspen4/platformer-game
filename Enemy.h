#ifndef ENEMY_H
#define ENEMY_H

#include "PhysicsObject.h"
#include "Player.h"

// enemies all kill the player on contact
class Enemy : public PhysicsObject {
public:
    using PhysicsObject::PhysicsObject;
    bool collide(Player *p) override;
};

#endif
