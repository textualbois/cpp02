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

	private:
		int					_value;
		static const int	_fractional_bits;
};

std::ostream& operator<<(std::ostream& os, const Fixed &fixed_number);

#endif