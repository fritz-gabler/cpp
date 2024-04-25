#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		//Constructors
		Fixed( void );
		Fixed( const Fixed &fixed );
		~Fixed( void );
		Fixed( const int intNumber );
		Fixed( const float floatNumber );

		//Functions
		int			getRawBits( void ) const;
		void		setRawBits( int const raw );
		int			toInt( void ) const;
		float		toFloat( void ) const;
		static Fixed		&min( Fixed &first, Fixed &second);
		static const Fixed	&min( const Fixed &first, const Fixed &second);
		static Fixed		&max( Fixed &first, Fixed &second);
		static const Fixed	&max( const Fixed &first, const Fixed &second);

		//Overloads
		Fixed &operator = ( const Fixed &other );

		bool operator > ( const Fixed &other ) const;
		bool operator < ( const Fixed &other ) const;
		bool operator >= ( const Fixed &other ) const;
		bool operator <= ( const Fixed &other ) const;
		bool operator == ( const Fixed &other ) const;
		bool operator != ( const Fixed &other ) const;

		Fixed operator + ( const Fixed &other ) const;
		Fixed operator - ( const Fixed &other ) const;
		Fixed operator * ( const Fixed &other ) const;
		Fixed operator / ( const Fixed &other ) const;

		Fixed &operator ++ ( void );
		Fixed operator ++ ( int );
		Fixed &operator -- ( void );
		Fixed operator -- ( int );

	private:
		int					_fixedPointNumber;
		static const int	_fractionalValue = 8;
};

std::ostream &operator<<(std::ostream &outStream, const Fixed &fixed);

#endif
