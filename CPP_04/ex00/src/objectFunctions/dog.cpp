/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:57:26 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/26 12:33:42 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

Dog::Dog( void ) :
	Animal("Dog")
{
	std::cout << "[ DOG ] Default constructor called" << std::endl;
}

Dog::Dog( const Dog &other ) :
	Animal(other._type)
{
	std::cout << "[ DOG ] Copy constructor called" << std::endl;
}

Dog &Dog::operator = (const Dog &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << "[ DOG ] Copy assignment constructor called" << std::endl;
	return (*this);
}

Dog::~Dog( void )
{
	std::cout << "[ DOG ] Destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "A known Dog sound: WAFF WAFF" << std::endl;
}
