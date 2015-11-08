#pragma once

/** 10.5 Given two squares on a two dimensional plane, find a line that would cut these two squares in half.
 * ========================================================================================================
 * Any line that goes through the center of a rectangle must cut it in half. Therefore, if you drew a line
 * connecting the centers of the two squares, it would cut both in half.
**/

struct Point
{
	Point(double x, double y)
		: x(x)
		, y(y) {}
	double x;
	double y;
};

struct Line
{
	Line(Point const &x, Point const &y)
		: x(x)
		, y(y) {}
	Point x;
	Point y;
};

class Square
{
public:
	Square(double x = 0, double y = 0, double len = 1)
		: leftTop(Point(x, y))
		, rightTop(Point(x + len, y))
		, leftBottom(Point(x, y + len))
		, rightBottom(Point(x + len, y + len)) {}
	Point getMiddle() const
	{
		return Point((double)(rightTop.x - leftTop.x) / 2.0, (double)(leftBottom.y - leftTop.y) / 2.0);
	}
private:
	Point leftTop;
	Point rightTop;
	Point leftBottom;
	Point rightBottom;
};

Line cutSquares(Square const &square1, Square const &square2)
{
	return Line(square1.getMiddle(), square2.getMiddle());
}
