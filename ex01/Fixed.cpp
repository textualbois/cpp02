#include "Fixed.hpp"


const int Fixed::_fractional_bits = 8;

Fixed::Fixed()
	: _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int &value) {
	std::cout << "Int constructor called" << std::endl;
	_value = value << _fractional_bits;
}

Fixed::Fixed(const float &value) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _fractional_bits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &src) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_value = src.getRawBits();
	else
		std::cout << "Self-assignment blocked" << std::endl;
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed_number) {
	os << fixed_number.toFloat();
	return os;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_value) / (1 << _fractional_bits);
}

int Fixed::toInt(void) const {
	return _value >> _fractional_bits;
}
