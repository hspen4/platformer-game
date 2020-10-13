#ifndef END_H
#define END_H

#include "CollisionObject.h"

class End : public CollisionObject {
public:
	// inherit constructors
	using CollisionObject::CollisionObject;
	// special collide behaviour
	virtual bool collide(Player *p);
};

#endif