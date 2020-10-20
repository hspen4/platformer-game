#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "Score.h"
#include <vector>

class Scoreboard {
public:
	Scoreboard(std::string file);
	~Scoreboard();
	void add_score(Score);
	std::vector <Score> get_scores();
	void set_scores(std::vector <Score>);
private:
	std::string file;
	std::vector <Score> scores;
	int entries;
};

#endif
