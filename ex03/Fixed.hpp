#ifndef FIXED_HH
#define FIXED_HH

#include <string.h>
#include <iostream>
#include <cmath>

class Fixed
{
	public:
	Fixed(void);
	Fixed(const Fixed &nb);
	Fixed &operator=(const Fixed &b);
	Fixed(const int &numb);
	Fixed(const float &numb);
	bool operator>(Fixed const & rhs) const;
	bool operator<(Fixed const & rhs) const;
	bool operator>=(Fixed const & rhs) const;
	bool operator<=(Fixed const & rhs) const;
	bool operator==(Fixed const & rhs) const;
	bool operator!=(Fixed const & rhs) const;
	Fixed operator+(Fixed const & rhs);
	Fixed operator-(Fixed const & rhs);
	Fixed operator*(Fixed const & rhs);
	Fixed operator/(Fixed const & rhs);
	Fixed &operator++(int);
	Fixed operator++();
	Fixed &operator--(int);
	Fixed operator--();
	~Fixed(void);
	static Fixed min(Fixed const & lhs, Fixed const & rhs);
	static Fixed min(Fixed & lhs, Fixed & rhs);
	static Fixed max(Fixed & lhs, Fixed & rhs);
	static Fixed max(Fixed const & lhs, Fixed const & rhs);
	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
	private:
	int _nb;
	static const int _nb2;
};

// left handside lhs rhs

std::ostream & operator<<(std::ostream & o, Fixed const & nb);

// std::cout << (int 42);

#endif