#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed &src);
		~Fixed();
		Fixed&	operator=(const Fixed &src);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_value;
		static const int	_fractional_bits = 8;
};

#endif