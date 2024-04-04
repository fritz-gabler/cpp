/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:22:05 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/03 17:20:45 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	this->_FixedPointNumber = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_FixedPointNumber = fixed._FixedPointNumber;
}

Fixed &Fixed::operator = (const Fixed &other)
{
	if (&other == this)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	this->_FixedPointNumber = other._FixedPointNumber;
	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void )
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_FixedPointNumber);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_FixedPointNumber = raw;
}
