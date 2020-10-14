#ifndef END_H
#define END_H

#include "CollisionObject.h"

// object that ends the level when you collide with it, winning the game
class End : public CollisionObject {
public:
	// inherit constructors
	using CollisionObject::CollisionObject;
	// special collide behaviour
	virtual bool collide(Player *p);
};

#endif
