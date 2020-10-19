#include "Score.h"

// constructor

Score::Score(std::string name, int points) 
	: name(name)
	, points(points)
{}

// getters and setters

Score::get_points() { return points; }
Score::get_name() { return name; }
Score::set_points(int pts) { points = pts; }
Score::set_name(std::string str) { name = str; }