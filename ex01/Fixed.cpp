#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int val) {
    value = val << fractionalBits;
    cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float val) {
    value = val * (1 << fractionalBits);
    cout << "Float constructor called" << endl;
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

float   Fixed::toFloat(void) const {
    return ((float) value / (float) (1 << fractionalBits));
}

int     Fixed::toInt(void) const {
    return (roundf((*this).toFloat()));
}

int		Fixed::getRawBits(void) const {
	cout << "getRawBits member function called" << endl;
	return (value);
}

void	Fixed::setRawBits(int const raw) {
    value = raw;
	cout << "setRawBits member function called" << endl;
}

std::ostream&   operator<<(std::ostream& output, const Fixed& val) {
    return (output << val.toFloat());
}
