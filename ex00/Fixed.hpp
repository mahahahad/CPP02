#pragma once
#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

using std::cout;
using std::endl;

class Fixed {
	public:
		Fixed();
		Fixed( Fixed &copy );
		Fixed	&operator=(const Fixed& x);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	private:
		int	value;
		static const int fractionalBits = 8;
};

#endif
