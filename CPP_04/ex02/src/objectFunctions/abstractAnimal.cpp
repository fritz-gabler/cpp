/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstractAnimal.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:20:20 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/26 13:17:55 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

AbstractAnimal::AbstractAnimal( void ) :
	_type("An unidentifiable creature")
{
	std::cout << "[ ABSTRACT ANIMAL ] Default constructor called" << std::endl;
}

AbstractAnimal::AbstractAnimal ( const AbstractAnimal &other ) :
	_type(other._type)
{
	std::cout << "[ ABSTRACT ANIMAL ] Copy constructor called" << std::endl;
}

AbstractAnimal::AbstractAnimal( const std::string type)
	: _type(type)
{
	std::cout << "[ ABSTRACT ANIMAL ] Constructor with arguments called" << std::endl;
}

AbstractAnimal &AbstractAnimal::operator = ( const AbstractAnimal &other )
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "[ ABSTRACT ANIMAL ] Copy assignment constructor called" << std::endl;
	return (*this);
}

AbstractAnimal::~AbstractAnimal( void )
{
	std::cout << "[ ABSTRACT ANIMAL ] Destructor called" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void	AbstractAnimal::makeSound( void ) const
{
	std::cout << "A crazy animal sound: QUAKIBAKI" << std::endl;
}

std::string	AbstractAnimal::getType( void ) const
{
	return (this->_type);
}
