#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

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
		std::ostream&	operator<<(std::ostream &out);

	private:
		int					_value;
		static const int	_fractional_bits;
};

#endif