#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <ostream>
# include <string>
# include <cmath>

class Fixed {
	public:
		Fixed();
		Fixed( const Fixed &src );
		Fixed( const int &value );
		Fixed( const float &value );
		~Fixed();
		Fixed&	operator=(const Fixed &src);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		// Comparison operators
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// Arithmetic operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		// Increment/Decrement operators
		Fixed& operator++(); // Pre-increment
		Fixed operator++(int); // Post-increment
		Fixed& operator--(); // Pre-decrement
		Fixed operator--(int); // Post-decrement

		// Static min/max functions
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);

	private:
		int					_value;
		static const int	_fractional_bits;
};

std::ostream& operator<<(std::ostream& os, const Fixed &fixed_number);

#endif