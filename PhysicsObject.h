#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include "CollisionObject.h"

class PhysicsObject : public CollisionObject {
public:
    PhysicsObject(char sprite, int x = 0, int y = 0);
    // called on every game tick - should apply momentum, gravity, etc
    virtual void tick();
    void render() override;
    void incrementTick();
    void resetTick();
    int getTick();
    int getTickLimit();
    bool grounded();
    void setGrounded(bool);
    int getYMomentum();
    void setYMomentum(int);
    int getXMomentum();
    void setXMomentum(int);

protected:
    // old location for cleaning
    int oldY, oldX;
    // count when to tick physics
    int tickCount;
    const int tickLimit;

private:
    // apply momentum from arrow keys
    int yMomentum;
    int xMomentum;
    bool onGround; // check if object on ground
};

#endif
