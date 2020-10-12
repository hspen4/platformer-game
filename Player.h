#ifndef PLAYER_H
#define PLAYER_H

#include "PhysicsObject.h"

class Player : public PhysicsObject {
public:
    bool is_player = true;
    // inherit ctors
    using PhysicsObject::PhysicsObject;
    void tick() override;
    bool check_collision(Player *p) override;
    bool collide(Player *p) override;
private:
    void input(); // gets user input
};

#endif
