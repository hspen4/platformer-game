#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include "CollisionObject.h"

class PhysicsObject : public CollisionObject {
public:
    // inherit ctors
    using CollisionObject::CollisionObject;
    // called on every game tick - should apply momentum, gravity, etc
    void tick();
};

#endif
