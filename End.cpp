#include "End.h"
#include "GameState.h"
#include "Player.h"

// end point of the level

bool End::collide(Player *p) {
    p->set_state(GameState::Won); // user has won
    return true; // signal to remove sprite
}
