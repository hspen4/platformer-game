#ifndef SCORE_H
#define SCORE_H

#include <string>

// scores that make up a scoreboard

class Score {
public:
    Score(std::string, int);
    int get_points();
    std::string get_name();
    void set_points(int);
    void set_name(std::string);
    // for use in std::sort
    bool operator<(const Score &obj) const;

private:
    int points;
    std::string name;
};

#endif
