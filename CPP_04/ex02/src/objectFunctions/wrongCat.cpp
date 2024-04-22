/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:49:02 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/22 12:48:55 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

WrongCat::WrongCat( void )
{
	this->_type = "WrongCat";
	std::cout << "[ WRONG CAT ] Default constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat &other )
{
	this->_type = other._type;
	std::cout << "[ WRONG CAT ] Copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator = (const WrongCat &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "[ WRONG CAT ] Copy assignment constructor called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat( void )
{
	std::cout << "[ WRONG CAT ] Destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "An unknown WrongCat sound: MIAUZI RAUZI WAUZI" << std::endl;
}
