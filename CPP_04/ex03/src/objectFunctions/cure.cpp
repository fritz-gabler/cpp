/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:36:59 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/22 17:54:53 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

Cure::Cure( void )
{
	this->_type = "cure";
	//std::cout << "[ CURE ] Default constructor called" << std::endl;
}

Cure::Cure( const Cure &other )
{
	this->_type = other._type;
	//std::cout << "[ CURE ] Constructor with arguments called" << std::endl;
}

Cure	&Cure::operator = ( const Cure &other )
{
	void (other);
	//std::cout << "[ A MATERIA ] Copy assignment constructor called" << std::endl; return (*this);
	return (*this);
}

Cure::~Cure( void )
{
	//std::cout << "[ CURE ] Destructor called" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

Cure	*Cure::clone( void ) const
{
	return (new Cure(*this));
}

void	Ice::use( ICharacter &target )
{
	std::cout <<  "* heals " << target.getName() << "’s wounds *";
}
