#include "End.h"
#include "Player.h"
#include "GameState.h"

bool End::collide(Player *p) {
	p->set_state(GameState::Won);
	return true; // signal to remove sprite
}
