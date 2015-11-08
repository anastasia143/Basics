#pragma once
#include <iostream>

/** 8.6 Implement the "paint fill" function that one might see on many image editing programs.
 * That is, given a screen (represented by a 2-dimensional array of Colors), a point, and a new
 * color, fill in the surrounding area until you hit a border of that color.
**/

enum Color
{
	black, white, red, green
};

bool paintFill(Color** screen, int x, int y, Color ocolor, Color ncolor, size_t xLen, size_t yLen)
{
	if (x < 0 || x >= xLen || y < 0 || y >= yLen) {
		return false;
	}
	if (screen[y][x] == ocolor) {
		screen[y][x] = ncolor;
		paintFill(screen, x - 1, y, ocolor, ncolor, xLen, yLen); // left
		paintFill(screen, x + 1, y, ocolor, ncolor, xLen, yLen); // right
		paintFill(screen, x, y - 1, ocolor, ncolor, xLen, yLen); // top
		paintFill(screen, x, y + 1, ocolor, ncolor, xLen, yLen); // bottom
	}
	return true;
}

bool paintFill(Color** screen, int x, int y, Color ncolor, size_t xLen, size_t yLen) {
	return paintFill(screen, x, y, screen[y][x], ncolor, xLen, yLen);
}
