#include "Point.cpp"

Point::Point() : _x(0), _y(0)
{
	return ;
}

Point:: Point(const Point &nb)
{
	*this->nb;
}

Point &Point::operator=(const Point &nb)
{
	return *this;
}

Point::(const float a, const float b)
{
	_x = a;
	_y = b;
}

Point::~Point()
{
	return ;
}
