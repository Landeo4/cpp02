#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	return ;
}

Point::Point(const Point &nb) : _x(nb._x), _y(nb._y)
{

}

Point &Point::operator=(const Point &nb)
{
	std::cout << "copy assignement called" << std::endl;
}

Point::Point(const float a, const float b) : _x(a), _y(b)
{

}

Point::~Point()
{
	return ;
}

const Fixed Point::getX(void)
{
	return (this->_x);
}

const Fixed Point::getY(void)
{
	return (this->_y);
}
