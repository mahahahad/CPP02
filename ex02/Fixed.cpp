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

bool    Fixed::operator>(const Fixed& other) const {
    return (value > other.getRawBits());
}

bool    Fixed::operator<(const Fixed& other) const {
    return (value < other.getRawBits());
}

bool    Fixed::operator>=(const Fixed& other) const {
    return (value >= other.getRawBits());
}

bool    Fixed::operator<=(const Fixed& other) const {
    return (value <= other.getRawBits());
}

bool    Fixed::operator==(const Fixed& other) const {
    return (value == other.getRawBits());
}

bool    Fixed::operator!=(const Fixed& other) const {
    return (value != other.getRawBits());
}

Fixed&  Fixed::operator=(const Fixed& other) {
    cout << "Copy assignment operator called" << endl;
    value = other.getRawBits();
    return (*this);
}

Fixed   Fixed::operator+(const Fixed& other) const {
    Fixed   result;

    result.setRawBits(value + other.getRawBits());
    return (result);
}

Fixed   Fixed::operator-(const Fixed& other) const {
    Fixed   result;

    result.setRawBits(value - other.getRawBits());
    return (result);
}

Fixed   Fixed::operator*(const Fixed& other) const {
    Fixed   result;

    result.setRawBits((int64_t)value * other.getRawBits() >> fractionalBits);
    return (result);
}

Fixed   Fixed::operator/(const Fixed& other) const {
    Fixed   result;

    result.setRawBits(((int64_t)value << fractionalBits) / other.getRawBits());
    return (result);
}

Fixed&  Fixed::operator++(void) {
    value++;
    return (*this);
}

Fixed   Fixed::operator++(int) {
    Fixed   tmp(*this);
    operator++();
    return (tmp);
}

Fixed   &Fixed::operator--(void) {
    value--;
    return (*this);
}

Fixed   Fixed::operator--(int) {
    Fixed   tmp(*this);
    operator--();
    return (tmp);
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

const Fixed&   Fixed::max(const Fixed& num1, const Fixed& num2) {
    if (num1 < num2)
        return (num2);
    return (num1);
}

Fixed&   Fixed::max(Fixed& num1, Fixed& num2) {
    if (num1 < num2)
        return (num2);
    return (num1);
}

const Fixed&   Fixed::min(const Fixed& num1, const Fixed& num2) {
    if (num1 > num2)
        return (num2);
    return (num1);
}

Fixed&   Fixed::min(Fixed& num1, Fixed& num2) {
    if (num1 > num2)
        return (num2);
    return (num1);
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
