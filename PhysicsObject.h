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

protected:
    // for applying movement from arrow keys
    int yMomentum;
    int xMomentum;
    // old location for cleaning
    int oldY, oldX;
    // count when to tick physics
    int tickCount;
    const int tickLimit;
};

#endif
