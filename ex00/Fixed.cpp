#include "Fixed.hpp"

Fixed::Fixed() {
	value = 0;
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(Fixed &copy) {
	(void) copy;
	cout << "Copy constructor called" << endl;
}

Fixed::~Fixed() {
	cout << "Destructor called" << endl;
}

Fixed &Fixed::operator=(const Fixed& t) {
	cout << "Copy assignment operator called" << endl;
	(void) t;
	return (*this);
}

int		Fixed::getRawBits(void) const {
	cout << "getRawBits member function called" << endl;
	return (0);
}

void	Fixed::setRawBits(int const raw) {
	(void) raw;
	cout << "setRawBits member function called" << endl;
}
