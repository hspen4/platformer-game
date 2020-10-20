#ifndef COLLISIONOBJECT_H
#define COLLISIONOBJECT_H

#include "SpriteObject.h"

// CollisionObject needs to know about the Player class, but we can't include
// the Player classdef before defining CollisionObject because it inherits from
// it
// forward declare the Player class instead so that this works
class Player;

// interface for any object that can collide with the player
class CollisionObject : public SpriteObject {
public:
    // inherit ctors
    using SpriteObject::SpriteObject;
    // is this object colliding with the player?
    virtual bool check_collision(Player *p);
    // handle a collision
    virtual bool collide(Player *p) = 0;
};

#endif
