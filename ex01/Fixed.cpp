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
	this->_nb = int (numb * (1 << this->_nb2));
}

// doit convert a la numb en nb a virgule
// regarder les video pour s'aider
Fixed::Fixed(const float &numb)
{
	this->_nb = float (numb * (1 << this->_nb2));
}

float Fixed::toFloat(void) const
{
	return ((float)this->_nb / (float)(1 << this->_nb2));
}

int Fixed::toInt(void) const
{
	return ((int)this->_nb / (int)(1 << this->_nb2));
}
// doit tranformer le nombre a virgule en entier

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

// potentiellement garder int32_t
// e = (int64_t(a) * int64_t(b)) >> 16;
//24 pour entier
//8 pour fractionnaire
// la moitier des bits du int 4 sup a virgule 4 autre pour le reste
// 4.78 -> 4 = 4 bits et 78 4 dernier bits -> 8bits int