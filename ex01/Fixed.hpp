#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

using std::cout;
using std::endl;

/*
Integers have 32 bits
0000 0000 0000 0000 0000 0000 0000 0000
The least significant bit is 2^0 = 1  ^

Fixed point numbers store values through integers by changing some part of the integer bits to store the fractional part of the number.

Setting the fractionalBits to 8 means that the 8 right most bits are meant for the fractional part of a number and the remaining are for the integer part.

0000 0000 0000 0000 0000 0000.0000 0000

Converting the number 1 from integer to a fixed point would mean moving it from 
0000 ... 0001
to
0000 ... 0001.0000 0000

This raw value is now 256

Storing decimal numbers is done by:
1. Shifting 1 to the left by fractionalBits and obtaining the respective number
2. Multiplying this new number by the decimal number
    This produces an integer which contains the decimal part within it
    This decimal part can be obtained by converting the number to its binary representation and isolating the fractionalBits amount of bits from the right.
    These bits are the values that add up to the decimal part of the original number
3. Storing the result in an integer (which loses the decimals obtained by multiplication if there were any and reduces the accuracy of the number)
*/
class Fixed {
	public:
		Fixed();
		Fixed( const Fixed& copy );
        Fixed( const float val );
        Fixed( const int val );
		~Fixed();
		Fixed	&operator=(const Fixed& x);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
	private:
		int	value;
		static const int fractionalBits = 8;
};

std::ostream&   operator<<(std::ostream& output, const Fixed& val);

#endif
