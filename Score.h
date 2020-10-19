#ifndef SCORE_h
#define SCORE_H

#include <string>

class Score {
public:
	Score(std::string, int);
	int get_points();
	std::string get_name();
	void set_points(int);
	void set_name(std::string);
private:
	int points;
	std::string name;
};
