#include "Fixed.hpp"

const int Fixed:: _nb2 = 8;

Fixed:: Fixed(void) : _nb(0)
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

Fixed::Fixed(const int &numb)
{
	
	*this = numb;
}// doit convert a la numb en nb a virgule

Fixed::Fixed(const float &numb)
{
	*this = numb;
}

void toFloat(void)
{
	*this = ;
}

int toInt(void)
{

}
// je dois aussi ajouter une fonction qui surcharge << qui envois un float de la valeur
// vers l'ouput (print quoi) passer en parametre

int Fixed::getRawBits(void) const
{
	return this->_nb;
}

void Fixed::setRawBits(int const raw)
{
	this->_nb = raw;
}

std::ostream & operator<<( std::ostream & o, Fixed const & nb)
{
	o << nb.getRawBits();
	return o;
}

//24 pour entier
//8 pour fractionnaire