#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <string.h>
#include <iostream>
#include <cmath>

class Point
{
	public:
	Point();
	Point(const Point &nb);
	Point &operator=(const Point &nb);
	Point(const float a, const float b);
	const Fixed getX();
	const Fixed getY();
	~Point();
	private:
	Fixed const _x;
	Fixed const _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif