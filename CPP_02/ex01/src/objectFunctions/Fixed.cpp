/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:22:05 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/04 18:12:56 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	this->_fixedPointNumber = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int intNumber )
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointNumber = intNumber << _fractionalValue;
}

Fixed::Fixed( const float floatNumber)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointNumber = roundf(floatNumber * (1 << _fractionalValue));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointNumber = fixed._fixedPointNumber;
}

Fixed &Fixed::operator = (const Fixed &other)
{
	if (&other == this)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointNumber = other._fixedPointNumber;
	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void )
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointNumber);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointNumber = raw;
}

int Fixed::toInt( void ) const
{
	return (this->_fixedPointNumber >> this->_fractionalValue);
}

float Fixed::toFloat( void ) const
{
	return (this->_fixedPointNumber / pow(2, _fractionalValue));
}

std::ostream &operator << (std::ostream &outStream, const Fixed &fixed)
{
	outStream << fixed.toFloat();
	return (outStream);
}
