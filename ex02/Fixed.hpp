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
        Fixed   &operator=( const Fixed& other );
        bool    operator>( const Fixed& other ) const;
        bool    operator<( const Fixed& other ) const;
        bool    operator>=( const Fixed& other ) const;
        bool    operator<=( const Fixed& other ) const;
        bool    operator==( const Fixed& other ) const;
        bool    operator!=( const Fixed& other ) const;
        Fixed   operator+( const Fixed& other ) const;
        Fixed   operator-( const Fixed& other ) const;
        Fixed   operator*( const Fixed& other ) const;
        Fixed   operator/( const Fixed& other ) const;
        // Pre-increment
        Fixed&  operator++( void );
        // Post-increment
        Fixed   operator++( int );
        // Pre-decrement
        Fixed&  operator--( void );
        // Post-decrement
        Fixed   operator--( int );
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
        static Fixed&  min( Fixed& num1, Fixed& num2 );
        static const Fixed&  min( const Fixed& num1, const Fixed& num2 );
        static Fixed&  max( Fixed& num1, Fixed& num2 );
        static const Fixed&  max( const Fixed& num1, const Fixed& num2 );
    private:
        int	value;
        static const int fractionalBits = 8;
};

std::ostream&   operator<<( std::ostream& output, const Fixed& val );

#endif
