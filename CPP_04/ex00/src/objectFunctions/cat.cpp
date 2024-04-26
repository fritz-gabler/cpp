/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:49:02 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/26 12:32:02 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Cat::Cat( void ) :
	Animal("Cat")
{
	std::cout << "[ CAT ] Default constructor called" << std::endl;
}

Cat::Cat( const Cat &other ) :
	Animal(other._type)
{
	std::cout << "[ CAT ] Copy constructor called" << std::endl;
}

Cat &Cat::operator = (const Cat &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "[ CAT ] Copy assignment constructor called" << std::endl;
	return (*this);
}

Cat::~Cat( void )
{
	std::cout << "[ CAT ] Destructor called" << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << "An usual cat sound: Miauuuu" << std::endl;
}
