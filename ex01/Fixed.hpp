#ifndef FIXED_HH
#define FIXED_HH

#include <string.h>
#include <iostream>

class Fixed
{
	public:
	Fixed(void);
	Fixed(const Fixed &nb);
	Fixed &operator=(const Fixed &b);
	Fixed(const int &numb);
	Fixed(const float &numb);
	~Fixed(void);
	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
	private:
	int _nb;
	static const int _nb2;
};

std::ostream & operator<<(std::ostream & o, Fixed const & nb)

#endif