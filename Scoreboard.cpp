#include "Scoreboard.h"
#include "Score.h"
#include <fstream>

// set up scoreboard, reading from existing file if available

Scoreboard::Scoreboard(const std::string file) : file(file) {

	// set up file reading

	std::ifstream ifs;
	ifs.open(file);

	// check if empty, create file if so

	if (ifs.peek() == std::ifstream::traits_type::eof()) {
		ifs.close();
		std::ofstream ofs;
		ofs.open(file);
		entries = 0;
		ofs << entries << '\n';
		return;
	}

	// get number of entries

	ifs >> entries; 

	for (int i = 0; i < entries; i++) {
		std::string name;
		int score;
		ifs >> name >> score;
		Score temp(name, score);
		scores.push_back(temp);
	}

}

// add a new score to the board

void Scoreboard::add_score(Score sc) {
	scores.push_back(sc);
}

// destructor

Scoreboard::~Scoreboard() {
	// clear existing file
	std::ofstream ofs;
	ofs.open(file);

	// write entries
	ofs << entries << '\n';

	// write scores
	for (int i = 0; i < entries; i++) {
		ofs << scores.at(i).get_name() << " " << scores.at(i).get_points() << '\n';
	}

	ofs.close();

}

std::vector<Score> Scoreboard::get_scores() { return scores; }

