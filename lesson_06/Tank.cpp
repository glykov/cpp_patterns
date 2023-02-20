#include <iostream>
#include <string>
#include <cstdlib>
#include "Tank.h"

bool Tank::is_inside(double x1, double x2) const
{
    const double x_beg = x + 2;
    const double x_end = x + width - 1;

    if (x1 < x_beg && x2 > x_end) {
		return true;
	}

	if (x1 > x_beg && x1 < x_end) {
		return true;
	}

	if (x2 > x_beg && x2 < x_end) {
		return true;
	}

	return false;
}

void Tank::draw() const
{
    std::cout << "drawing a tank\n";
}

void Tank::tease_the_plane() const
{
    std::string messages[] = {
        "Miss Me!", "Try to Catch Me!", "Ha-ha"
    };
    int msg = rand() % 3;
    mediator->notify(this, messages[msg]);
}

void Tank::be_notified(std::string message) const
{
    std::cout << "message: " << message << std::endl;
}