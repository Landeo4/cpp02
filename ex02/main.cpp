#include "Fixed.hpp"

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "plus sign" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << "now minus sign" << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	Fixed c(10);
	Fixed d;
	std::cout << " + - * and /" << std::endl;
	// c.setRawBits(10);
	// d.setRawBits(3);
	std::cout << c << std::endl;
	// std::cout << c.getRawBits() << std::endl;
	std::cout << c << " + 3 = " << Fixed(c + 3) << std::endl;
	std::cout << c << " - 2 = " << Fixed(c - 2) << std::endl;
	std::cout << c << " * 3 = " << Fixed(c * 3) << std::endl;
	std::cout << c << " / 2 = " << Fixed(c / 2) << std::endl;

	std::cout << "> < >= <= == !=" << std::endl;
	std::cout << "10 > 2 = " << Fixed(c > 2) << std::endl;
	std::cout << "10 < 2 = " << Fixed(c < 2) << std::endl;
	std::cout << "10 >= 2 = " << Fixed(c >= 2) << std::endl;
	std::cout << "10 <= 2 = " << Fixed(c <= 2) << std::endl;
	std::cout << "10 == 2 = " << Fixed(c == 2) << std::endl;
	std::cout << "10 != 2 = " << Fixed(c != 2) << std::endl;

	std::cout << "min and max" << std::endl;

	Fixed e(5);
	Fixed i(2);
	Fixed j (Fixed( 5.05f ));
	Fixed u (Fixed( 2.05f ));
	std::cout << Fixed::max( e, i ) << std::endl;
	std::cout << Fixed::max( j, u ) << std::endl;
	std::cout << Fixed::min( e, i ) << std::endl;
	std::cout << Fixed::min( j, u ) << std::endl;
	return 0;
}
