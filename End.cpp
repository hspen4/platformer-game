#include "End.h"
#include "GameState.h"
#include "Player.h"

bool End::collide(Player *p) {
    p->set_state(GameState::Won);
    return true; // signal to remove sprite
}
