/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:49:02 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/17 20:20:05 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

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
	std::cout << "[ Wrong CAT ] Copy assignment constructor called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat( void )
{
	std::cout << "[ WRONG CAT ] Destructor called" << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Wait, that doesn't "
		<< "soud like a cat sounds wrong: Mauki paui lauky"
		<< std::endl;
}
