#include "CollisionObject.h"
#include "Player.h"
#include "Scene.h"

#include <iostream>

bool CollisionObject::check_collision(Player *p) {
    // occupying the same space
    return p->get_x() == x && p->get_y() == y;
}

// remove ourself from the scene so we stop colliding
// TODO at some point this should be probably be abstract
bool CollisionObject::collide(Player *p) { return true; }
