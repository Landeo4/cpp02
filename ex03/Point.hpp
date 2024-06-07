#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
	Point();
	Point(const Point &nb);
	Point &operator=(const Point &nb);
	Point(const float a, const float b);
	~Point();
	private:
	Fixed const _x;
	Fixed const _y;
};

#endif