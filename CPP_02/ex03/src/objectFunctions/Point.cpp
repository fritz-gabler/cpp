/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:47:25 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/09 16:39:34 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Point::Point( void ) : _x(0), _y(0) {}

Point::~Point(void){}

Point::Point( const Point &other) : _x(other._x), _y(other._y) {}

Point::Point( const float x, const float y) : _x(x), _y(y) {}

Point &Point::operator = (const Point &other)
{
	(void) other;
	return (*this);
}

Fixed Point::getX( void ) const
{
	return (this->_x);
}

Fixed Point::getY( void ) const
{
	return (this->_y);
}
