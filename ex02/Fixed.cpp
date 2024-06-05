#include "Fixed.hpp"

const int Fixed:: _nb2 = 8;

Fixed:: Fixed(void) : _nb(0)
{
	std::cout << "default constructor called" << std::endl;
	return ;
}

Fixed:: ~Fixed(void)
{
	std::cout << "destructor called" << std::endl;
	return ;
}

Fixed:: Fixed(const Fixed &nb)
{
	std::cout << "copy constructor called" << std::endl;
	*this = nb;
}

Fixed &Fixed::operator =(const Fixed &b)
{
	std::cout << "copy assignement called" << std::endl;
	if (this != &b)
	{
		this->_nb = b.getRawBits();
	}
	return *this;
}

Fixed::Fixed(const int &numb)
{
	std::cout << "int constructor called" << std::endl;
	this->_nb = (int)(numb << this->_nb2);
}

// doit convert a la numb en nb a virgule
// regarder les video pour s'aider

Fixed::Fixed(const float &numb)
{
	std::cout << "float constructor called" << std::endl;
	this->_nb = float(numb * (1 << this->_nb2));
}

float Fixed::toFloat(void) const
{
	return ((float)this->_nb / (float)(1 << this->_nb2));
}

int Fixed::toInt(void) const
{
	return ((int)this->_nb / (int)(1 << this->_nb2));
}

int Fixed::getRawBits(void) const
{
	return this->_nb;
}

void Fixed::setRawBits(int const raw)
{
	this->_nb = raw;
}

Fixed &Fixed::operator>(Fixed const & rhs)
{
	this->_nb > rhs._nb;
	return (*this);
}

Fixed &Fixed::operator<(Fixed const & rhs)
{
	this->_nb < rhs._nb;
	return (*this);
}

Fixed &Fixed::operator>=(Fixed const & rhs)
{
	this->_nb >= rhs._nb;
	return (*this);
}

Fixed &Fixed::operator<=(Fixed const & rhs)
{
	this->_nb <= rhs._nb;
	return (*this);
}

Fixed &Fixed::operator==(Fixed const & rhs)
{
	this->_nb == rhs._nb;
	return (*this);
}

Fixed &Fixed::operator!=(Fixed const & rhs)
{
	this->_nb != rhs._nb;
	return (*this);
}

Fixed &Fixed::operator+(Fixed const & rhs)
{
	this->_nb += rhs._nb;
	return (*this);
}

Fixed &Fixed::operator-(Fixed const & rhs)
{
	this->_nb - rhs._nb;
	return (*this);
}

Fixed &Fixed::operator*(Fixed const & rhs)
{
	this->_nb * rhs._nb;
	return (*this);
}

Fixed &Fixed::operator/(Fixed const & rhs)
{
	this->_nb / rhs._nb;
	return (*this);
}

Fixed &Fixed::operator++(int){return *this;}

Fixed &Fixed::operator++(){return *this;}

Fixed &Fixed::operator--(int){return *this;}

Fixed &Fixed::operator--(){return *this;}

Fixed Fixed::min(Fixed const & lhs, Fixed const & rhs)
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	else if (lhs.getRawBits() > rhs.getRawBits())
		return (rhs);
	return rhs;
}

Fixed Fixed::min(Fixed & lhs, Fixed & rhs)
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	else if (lhs.getRawBits() > rhs.getRawBits())
		return (rhs);
	return rhs;
}

Fixed Fixed::max(Fixed & lhs, Fixed & rhs)
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return (rhs);
	else if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return rhs;
}

Fixed &Fixed::max(Fixed const & lhs, Fixed const & rhs)
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return (rhs);
	else if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return this;
}

std::ostream & operator<<( std::ostream & o, Fixed const & nb)
{
	o << nb.toFloat();
	return o;
}

//pour BSP utiliser la methode Vectoriel
// il y a deux Vecteurs qui te dise avec des rotations un point

// potentiellement garder int32_t
// e = (int64_t(a) * int64_t(b)) >> 16;
//24 pour entier
//8 pour fractionnaire
// la moitier des bits du int 4 sup a virgule 4 autre pour le reste
// 4.78 -> 4 = 4 bits et 78 4 dernier bits -> 8bits int