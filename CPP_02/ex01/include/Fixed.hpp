#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed( void );
		Fixed(	const Fixed &fixed );
		Fixed &operator = ( const Fixed &other );
		~Fixed( void );
		Fixed( const int intNumber );
		Fixed( const float floatNumber );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		int		toInt( void ) const;
		float	toFloat( void ) const;

	private:
		int					_fixedPointNumber;
		static const int	_fractionalValue = 8;
};

std::ostream &operator<<(std::ostream &outStream, const Fixed &fixed);

#endif
