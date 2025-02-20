#include "Fixed.hpp"

Fixed::Fixed() {
    value = 0;
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

Fixed&  Fixed::operator=(const Fixed& t) {
    cout << "Copy assignment operator called" << endl;
    value = t.getRawBits();
    return (*this);
}

/**
 * @brief Convert the Fixed point number to a floating point number
 * 
 * @return float The converted floating point number, with `fractionalBits` amount of precision
 */
float   Fixed::toFloat(void) const {
    return ((float) value / (float) (1 << fractionalBits));
}

/**
 * @brief Convert the Fixed point number to an integer
 * 
 * @return int The converted integer, rounded up
 */
int     Fixed::toInt(void) const {
    return (roundf((*this).toFloat()));
}

/**
 * @brief Get the raw value of the Fixed point number
 * 
 * @return int The integer representation of the Fixed point number
 */
int     Fixed::getRawBits(void) const {
    cout << "getRawBits member function called" << endl;
    return (value);
}

/**
 * @brief Manually change the raw value of the Fixed point number
 * 
 * @param raw The new value to overwrite with
 */
void    Fixed::setRawBits(int const raw) {
    value = raw;
    cout << "setRawBits member function called" << endl;
}

/**
 * @brief Stream insertion overload
 * 
 * Allows users to simply insert a Fixed point number like the other number types into the provided stream
 * 
 * @param output The stream to insert into 
 * @param fixedNum The Fixed point number to insert 
 * @return std::ostream&
 */
std::ostream&   operator<<(std::ostream& output, const Fixed& fixedNum) {
    return (output << fixedNum.toFloat());
}
