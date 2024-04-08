#ifndef POINT_HPP
#define POINT_HPP

#include "header.hpp"

class Point
{
	public:
		Point( void );
		~Point( void );
		Point( const Point &other );
		Point( const float x, const float y );
		Point &operator = (const Point &other);

		Fixed	getX( void ) const;
		Fixed	getY( void ) const;
	private:
		Fixed const	_x;
		Fixed const _y;
};

#endif
