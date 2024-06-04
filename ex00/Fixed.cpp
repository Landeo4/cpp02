#include "Fixed.hpp"

Fixed:: Fixed(void)
{
	return ;
}

Fixed:: ~Fixed(void)
{
	return ;
}

Fixed:: Fixed(const Fixed &nb)
{
	*this = nb;
}

Fixed &Fixed::operator =(const Fixed &b)
{
	if (this != &b)
	{
		this->_nb = b.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->_nb;
}

void Fixed::setRawBits(int const raw)
{
	this->_nb = raw;
}

//24 pour entier
//8 pour fractionnaire