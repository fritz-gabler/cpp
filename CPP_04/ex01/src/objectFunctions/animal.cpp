/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:20:20 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/17 21:02:47 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

Animal::Animal( void )
{
	this->_type = "An unidentifiable creature";
	std::cout << "[ ANIMAL ] Default constructor called" << std::endl;
}

Animal::Animal ( const Animal &other )
{
	this->_type = other._type;
	std::cout << "[ ANIMAL ] Copy constructor called" << std::endl;
}

Animal &Animal::operator = ( const Animal &other )
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "[ ANIMAL ] Copy assignment constructor called" << std::endl;
	return (*this);
}

Animal::~Animal( void )
{
	std::cout << "[ ANIMAL ] Destructor called" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void	Animal::makeSound( void ) const
{
	std::cout << "A crazy animal sound: QUAKIBAKI" << std::endl;
}

std::string	Animal::getType( void ) const
{
	return (this->_type);
}
