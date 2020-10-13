#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

#include "CollisionObject.h"

class Collectible : public CollisionObject {
public:
	// inherit constructors
	using CollisionObject::CollisionObject;
	// special collide behaviour
	virtual bool collide(Player *p);
};

#endif