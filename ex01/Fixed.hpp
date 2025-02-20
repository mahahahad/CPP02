#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>

using std::cout;
using std::endl;

/**
 * @brief Fixed point number
 * 
 * Can be constructed with an int and a float 
 * 
 * Stores decimal values using 8 fractionalBits
 * 
 */
class Fixed {
    public:
        Fixed();
        Fixed( const Fixed& copy );
        Fixed( const float val );
        Fixed( const int val );
        ~Fixed();
        Fixed   &operator=(const Fixed& x);
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
    private:
        int	value;
        static const int fractionalBits = 8;
};

std::ostream&   operator<<(std::ostream& output, const Fixed& val);

#endif
