#include "Score.h"
#include <algorithm>

// constructor
Score::Score(std::string name, int points)
    : points(points)
    , name(name)
{
    if (!name.length()) this->name = "[blank]";
}

// overload less than operator for sorting
bool Score::operator<(const Score &obj) const {
	if (points == obj.points) {
		// if the scores are the same, sort alphabetically
		return (name > obj.name);
	}
	return (points < obj.points);
}

// getters and setters
int Score::get_points() { return points; }
std::string Score::get_name() { return name; }
void Score::set_points(int pts) { points = pts; }
void Score::set_name(std::string str) { name = str; }
