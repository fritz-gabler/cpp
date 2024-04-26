/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:57:26 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/26 12:37:18 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

WrongDog::WrongDog( void ) :
	WrongAnimal("WrongDog")
{
	std::cout << "[ WRONG DOG ] Default constructor called" << std::endl;
}

WrongDog::WrongDog( const WrongDog &other ) :
	WrongAnimal(other._type)
{
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
