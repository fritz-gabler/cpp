/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:20:20 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/17 14:55:37 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"
///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

Animal::Animal( void )
{
	this->_type = "An unidentifiable creature";
	std::cout << "[ Animal ] Default constructor called" << std::endl;
}

Animal::Animal ( const Animal &other )
{
	this->_type = other._type;
	std::cout << "[ Animal ] Copy constructor called" << std::endl;
}

Animal &Animal::operator = ( const Animal &other )
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "[ Animal ] Copy assignment constructor called" << std::endl;
	return (*this);
}

Animal::~Animal( void )
{
	std::cout << "[ Animal ] Destructor called" << std::endl;
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
