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
	// std::cout << "float constructor called" << std::endl;
	this->_nb = roundf(numb * (float)(1 << this->_nb2));
	std::cout << "constructeur float " << numb << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((float)(this->_nb / (float)(1 << this->_nb2)));
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
	std::cout << "get RawBits called" << std::endl;
	return this->_nb;
}

void Fixed::setRawBits(int const raw)
{
	this->_nb = raw;
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