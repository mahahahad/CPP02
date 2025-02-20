#include "Fixed.hpp"

Fixed::Fixed() {
	value = 0;
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const Fixed &copy) {
	cout << "Copy constructor called" << endl;
    value = copy.getRawBits();
}

Fixed::~Fixed() {
	cout << "Destructor called" << endl;
}

Fixed &Fixed::operator=(const Fixed& t) {
	cout << "Copy assignment operator called" << endl;
	value = t.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const {
	cout << "getRawBits member function called" << endl;
	return (value);
}

void	Fixed::setRawBits(int const raw) {
    value = raw;
	cout << "setRawBits member function called" << endl;
}
