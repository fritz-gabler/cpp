/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:51:10 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/26 12:38:00 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

WrongAnimal::WrongAnimal( void ) :
	_type("An unidentifiable creature")
{
	std::cout << "[ WRONG ANIMAL ] Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal ( const WrongAnimal &other ) :
	_type(other._type)
{
	std::cout << "[ WRONG ANIMAL ] Copy constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const std::string type )
	: _type(type)
{
	std::cout << "[ WRONG ANIMAL ] Constructor with arguments called" << std::endl;
}

WrongAnimal &WrongAnimal::operator = ( const WrongAnimal &other )
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "[ WRONG ANIMAL ] Copy assignment constructor called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "[ WRONG ANIMAL ] Destructor called" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "That sounds linke a Wrong Animal: JANKY PANKY" << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->_type);
}
