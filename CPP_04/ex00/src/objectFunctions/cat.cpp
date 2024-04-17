/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:49:02 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/17 14:56:42 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Cat::Cat( void )
{
	this->_type = "Cat";
	std::cout << "[ Cat ] Default constructor called" << std::endl;
}

Cat::Cat( const Cat &other )
{
	this->_type = other._type;
	std::cout << "[ Cat ] Copy constructor called" << std::endl;
}

Cat &Cat::operator = (const Cat &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "[ Cat ] Copy assignment constructor called" << std::endl;
	return (*this);
}

Cat::~Cat( void )
{
	std::cout << "[ Cat ] Destructor called" << std::endl;
}

void	Animal::makeSound( void ) const
{
	std::cout << "A usual cat sound: Miauuuu" << std::endl;
}
