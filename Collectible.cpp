#include "Collectible.h"
#include "Player.h"

bool Collectible::collide(Player *p) {
    p->set_score(p->get_score() + 100.0); // add 100 points
    return true; // signal to remove sprite
}