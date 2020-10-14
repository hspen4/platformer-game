#include "End.h"
#include "Player.h"

bool End::collide(Player *p) {
	p->set_playing(false);
	return true; // signal to remove sprite
}