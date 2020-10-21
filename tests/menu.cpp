#include "harness.h"
#include "../Scoreboard.h"
#include "../Score.h"
#include <fstream>
#include <ios>
#include "../menu.cpp"
#include <ncurses.h>

// test scoreboard tracking
void menu(Harness *assert) {
	initscr();
	assert->context("menus");
	Scoreboard *sb = new Scoreboard("scores/test_sb.txt");
	Score sc("test", 10);
	sb->add_score(sc);
	delete sb; // call destructor to push to file
	Scoreboard *sb2 = new Scoreboard("scores/test_sb.txt");
	assert->eq(sb2->get_scores().size(), 1, "didn't add score");
	delete sb2;
	std::ofstream ofs;
	ofs.open("scores/test_sb.txt", std::ios_base::trunc); // delete file after

	// test menu
	int lvl = menu(6);
	// check it did not take invalid input
	assert->neq(lvl, 7, "ignoring invalid input");
	// check it took a valid level
	assert->eq(lvl, 2, "not taking level");
	//lvl = menu(6);
	//assert->eq(lvl, KEY_BACKSPACE, "not exiting game");
	endwin();

}
