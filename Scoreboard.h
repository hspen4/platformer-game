#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "Score.h"
#include <vector>

// stores score info

class Scoreboard {
public:
    Scoreboard(std::string file);
    ~Scoreboard();
    void add_score(Score);
    std::vector<Score> get_scores();
    void set_scores(std::vector<Score>);

private:
    std::string file; // file to be read and write to
    std::vector<Score> scores; // held in ram during game
    int entries; // number of scores
};

#endif
