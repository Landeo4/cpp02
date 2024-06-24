#include "Fixed.hpp"

const int Fixed:: _nb2 = 8;

Fixed:: Fixed(void) : _nb(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed:: ~Fixed(void)
{
	std::cout << "Destuctor called" << std::endl;
	return ;
}

Fixed:: Fixed(const Fixed &nb)
{
	std::cout << "copy constructor called" << std::endl;
	*this = nb;
}

Fixed &Fixed::operator =(const Fixed &b)
{
	std::cout << "copy assignement operator called" << std::endl;
	if (this != &b)
	{
		this->_nb = b.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "get RawBits member function called" << std::endl;
	return this->_nb;
}

void Fixed::setRawBits(int const raw)
{
	this->_nb = raw;
}

//24 pour entier
//8 pour fractionnaire