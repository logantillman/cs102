#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

class Rectangle
{
public:
	Rectangle(const Point &p1, const Point &p2)
		: p1(p1), p2(p2) { }
private:
	Point p1, p2;
};

#endif // RECTANGLE_H
