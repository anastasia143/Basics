#pragma once
#include <list>
#include <iostream>

/** 8.2 Imagine a robot sitting on the upper left hand corner of an NxN grid.
 * The robot can only move in two directions: right and down. How many possible
 * paths are there for the robot?
 *
 * FOLLOW UP
 * Imagine certain squares are “off limits”, such that the robot can not step on them.
 * Design an algorithm to get all possible paths for the robot.
 * ===================================================================================
 * Part 1:
 * Since you must always move right X-1 times, and you have X-1 + Y-1 total steps, you have to pick X-1 times
 * to move right out of X-1+Y-1 choices. Thus, there are C(X-1, X-1+Y-1) paths (e.g., X-1+Y-1 choose X-1):
 * (X-1 + Y-1)! / ((X-1)! * (Y-1)!)
 * Part 2: Code
 * We can implement a simple recursive algorithm with backtracking:
**/

using namespace std;

struct Point
{
	Point(int x, int y)
		: x(x)
		, y(y) {}
	int x;
	int y;
};

bool operator==(const Point &p1, const Point &p2)
{
	return (p1.x == p2.x && p1.y == p2.y);
}

bool is_free(int x, int y)
{
	return true;
}

class Robot
{
public:
	Robot()
	{
	}

	list<Point> current_path;
	bool getPaths(int x, int y)
	{
		Point p(x, y);
		current_path.push_back(p);

		if (x == 0 && y == 0)
			return true; // current_path
		bool success = false;

		if (x >= 1 && is_free(x - 1, y)) { // Try right
			success = getPaths(x - 1, y); // Free! Go right
		}

		if (!success && y >= 1 && is_free(x, y - 1)) { // Try down
			success = getPaths(x, y - 1); // Free! Go down
		}

		if (!success) {
			current_path.remove(p); // Wrong way!
		}
		return success;
	}
};
