#include "Collectible.h"
#include "Player.h"
#include <ncurses.h>

extern int max_y, max_x;

bool Collectible::collide(Player *p) {
	p->set_score(p->get_score() + 10);
	for(int i = 0; i <= max_x; i++) {
		mvprintw(0,i," ");
	}
	mvprintw(0,0,"Score: %d", p->get_score());
	return true; // signal to remove sprite
}