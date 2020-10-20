#include "Collectible.h"
#include "Player.h"

bool Collectible::collide(Player *p) {
    p->set_score(p->get_score() + 10);
    return true; // signal to remove sprite
}