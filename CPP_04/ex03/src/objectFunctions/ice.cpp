/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:35:58 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/22 17:54:37 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

Ice::Ice( void )
{
	this->_type = "ice";
	//std::cout << "[ ICE ] Default constructor called" << std::endl;
}

Ice::Ice( const Ice &other )
{
	this->_type = other._type;
	//std::cout << "[ ICE ] Constructor with arguments called" << std::endl;
}

Ice &Ice::operator = ( const Ice &other )
{
	void (other);
	return (*this);
}

Ice::~Ice( void )
{
	//std::cout << "[ ICE ] Destructor called" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

Ice		*Ice::clone( void ) const
{
	return (new Ice(*this));
}

void	Ice::use( ICharacter &target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*\n";
}
