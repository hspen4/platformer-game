#include "harness.h"
#include "../Scoreboard.h"
#include "../Score.h"
#include <fstream>
#include <ios>

// test scoreboard tracking
void menu(Harness *assert) {
	assert->context("menus");
	Scoreboard *sb = new Scoreboard("scores/test_sb.txt");
	Score sc("test", 10);
	sb->add_score(sc);
	delete sb; // call destructor to push to file
	Scoreboard *sb2 = new Scoreboard("scores/test_sb.txt");
	assert->eq((int)(sb2->get_scores().size()), 1, "didn't add score");
	delete sb2;
	std::ofstream ofs;
	ofs.open("test_sb.txt", std::ios_base::trunc); // delete file after


}