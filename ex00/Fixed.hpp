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
	~Fixed(void);
	// cpt constructor
	// cpy assignement operator overload 

	int getRawBits(void) const;
	void setRawBits(int const raw);
	private:
	int _nb;
	static const int _nb2;
};

#endif