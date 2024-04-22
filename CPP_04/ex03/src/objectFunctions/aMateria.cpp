/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:35:45 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/20 18:46:32 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

AMateria::AMateria( void )
{
	this->_type = "DEFAULT";
//	std::cout << "[ A MATERIA ] Default constructor called" << std::endl;
}

AMateria::AMateria( const std::string &type )
{
	this->_type = type;
//	std::cout << "[ A MATERIA ] Constructor with arguments called" << std::endl;
}

AMateria::AMateria( const AMateria &other )
{
	this->_type = other._type;
//	std::cout << "[ A MATERIA ] Copy constructor called" << std::endl;
}

AMateria &AMateria::operator = ( const AMateria &other )
{

	if (this != &other)
		this->_type = other._type;
	return (*this);
//	std::cout << "[ A MATERIA ] Copy assignment constructor called" << std::endl; return (*this);
}

AMateria::~AMateria( void )
{
//	std::cout << "[ A MATERIA ] Destructor called" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

const std::string	AM
