#include "CollisionObject.h"
#include "Player.h"
#include "Scene.h"

#include <iostream>

bool CollisionObject::check_collision(Player *p) {
    // occupying the same space
    return p->get_render_x() == x && p->get_render_y() == y;
}
