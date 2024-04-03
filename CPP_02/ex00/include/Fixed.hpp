#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed( void );
		Fixed(const Fixed &fixed);
		Fixed &operator = (const Fixed &other);
		~Fixed( void );

		int getRawBits( void );
		void setRawBits( int const raw );

	private:
		int	_FixedPointNumber;
};

#endif
