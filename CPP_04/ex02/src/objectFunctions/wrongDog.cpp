/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:57:26 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/22 12:44:34 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

WrongDog::WrongDog( void )
{
	this->_type = "WrongDog";
	std::cout << "[ WRONG DOG ] Default constructor called" << std::endl;
}

WrongDog::WrongDog( const WrongDog &other )
{
	this->_type = other._type;
	std::cout << "[ WRONG DOG ] Copy constructor called" << std::endl;
}

WrongDog &WrongDog::operator = (const WrongDog &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "[ WRONG DOG ] Copy assignment constructor called" << std::endl;
	return (*this);
}

WrongDog::~WrongDog( void )
{
	std::cout << "[ WRONG DOG ] Destructor called" << std::endl;
}

void	WrongDog::makeSound() const
{
	std::cout << "An unknown WrongDog sound: WAFFEL RAUUFEL MUMPF MUMPF" << std::endl;
}
