#include "Fixed.hpp"

Fixed::Fixed() : _rawBit(0)
{
	//std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const int nb)
{
	//std::cout<<"Int constructor called"<<std::endl;
	_rawBit = nb<<_fractBit;
}

Fixed::Fixed(const float f)
{
	_rawBit = roundf(f * (float)(1<<_fractBit));
	//std::cout<<"Float constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	//std::cout<<"Copy constructor called"<<std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	//std::cout<<"Copy assignment operator called"<<std::flush;
	this->_rawBit = fixed._rawBit;
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void) const
{
	//std::cout<<"getRawBits member function called"<<std::endl;
	return(_rawBit);
}

void Fixed::setRawBits(const int value)
{
	//std::cout<<"setRawBits member function called"<<std::endl;
	_rawBit = value<<_fractBit;
}

float Fixed::toFloat( void ) const
{
	//std::cout<<"tofloat member function called"<<std::endl;
	return ((float)_rawBit/(float)(1<<_fractBit));
}

int Fixed::toInt( void ) const
{
	//std::cout<<"toInt member function called"<<std::endl;
	return (_rawBit>>8);
}

std::ostream &operator<<(std::ostream &o, const Fixed &rhs)
{
	//std::cout<<"operator << "<<std::flush;
	o << rhs.toFloat();
	return (o);
}


const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	//std::cout<<"compare min "<<std::flush;
	return (a < b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	//std::cout<<"compare max "<<std::flush;
	return (a > b ? a : b);
}

bool   Fixed::operator>(const Fixed &rhs) const
{
	//std::cout<<"operator > "<<std::flush;
	return (this->_rawBit > rhs._rawBit);
}

bool    Fixed::operator<(const Fixed &rhs) const
{
	//std::cout<<"operator < "<<std::flush;
	return (this->_rawBit < rhs._rawBit);
}

bool    Fixed::operator>=(const Fixed &rhs) const
{
	//std::cout<<"operator >= "<<std::flush;
	return (this->_rawBit >= rhs._rawBit);
}

bool   Fixed::operator<=(const Fixed &rhs) const
{
	//std::cout<<"operator <= "<<std::flush;
	return (this->_rawBit <= rhs._rawBit);
}

bool    Fixed::operator==(const Fixed &rhs) const
{
	//std::cout<<"operator == "<<std::flush;
	return (this->_rawBit == rhs._rawBit);
}

bool    Fixed::operator!=(const Fixed &rhs) const
{
	//std::cout<<"operator != "<<std::flush;
	return (this->_rawBit != rhs._rawBit);
}

Fixed Fixed::operator+(const Fixed &rhs)
{
	//std::cout<<" operator + "<<std::flush;
	return (this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs)
{
	//std::cout<<"operator - "<<std::flush;
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs)
{
	//std::cout<<"operator * "<<std::flush;
	return (this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs)
{
	//std::cout<<"operator / "<<std::flush;
	return (this->toFloat() / rhs.toFloat());
}

Fixed Fixed::operator++(int)
{
	//std::cout<<"operator ++ "<<std::flush;
	Fixed    tmp(*this);
	this->_rawBit += 1;
    return (tmp);
}

Fixed &Fixed::operator--(void)
{	
	//std::cout<<"operator -- "<<std::flush;
	this->_rawBit -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	//std::cout<<"-- operator "<<std::flush;
	Fixed    tmp(*this);
	this->_rawBit -= 1;
	return (tmp);
}

Fixed &Fixed::operator++(void)
{
	//std::cout<<"++operator "<<std::flush;
	this->_rawBit += 1;
	return (*this);
}