#ifndef PLAYER_H
#define PLAYER_H

#include "PhysicsObject.h"

class Player : public PhysicsObject {
public:
	// inherit ctors
    using PhysicsObject::PhysicsObject;
	void tick() override;
private:
	void input(); // gets user input

};

#endif