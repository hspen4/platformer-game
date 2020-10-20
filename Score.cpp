#include "Score.h"
#include <algorithm>

// constructor

Score::Score(std::string name, int points)
    : points(points)
    , name(name)
{}

// overload less than operator for sorting

bool Score::operator<(const Score &obj) const {
	if (points == obj.points) {
		/*std::string name_one, name_two;
		std::transform(name.begin(), name.end(), name_one.begin(), ::toupper);
		std::transform(obj.name.begin(), obj.name.end(), name_two.begin(), ::toupper);*/
		return (name > obj.name);
	}
	return (points < obj.points);
}

// getters and setters

int Score::get_points() { return points; }
std::string Score::get_name() { return name; }
void Score::set_points(int pts) { points = pts; }
void Score::set_name(std::string str) { name = str; }