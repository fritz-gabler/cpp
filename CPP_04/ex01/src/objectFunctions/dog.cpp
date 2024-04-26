/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:57:26 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/26 13:03:06 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

Dog::Dog( void )
{
	this->_type = "Dog";
	this->_brain = new Brain;
	std::cout << "[ DOG ] Default constructor called" << std::endl;
}

Dog::Dog( const Dog &other ) :
	Animal(other._type)
{
	this->_brain = new Brain(*(other._brain));
	std::cout << "[ DOG ] Copy constructor called" << std::endl;
}

Dog &Dog::operator = (const Dog &other)
{
	if (this != &other)
	{
		*(this->_brain) = *(other._brain);
		this->_type = other._type;
	}
	std::cout << "[ DOG ] Copy assignment constructor called" << std::endl;
	return (*this);
}

Dog::~Dog( void )
{
	delete _brain;
	std::cout << "[ DOG ] Destructor called" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void	Dog::makeSound() const
{
	std::cout << "A known Dog sound: WAFF WAFF" << std::endl;
}

void	Dog::saveNewIdea( const std::string &idea )
{
	this->_brain->saveNewIdea(idea);
}

void	Dog::changeAnIdea( const std::string &idea, int ideaNumber )
{
	this->_brain->changeAnIdea(idea, ideaNumber);
}

void	Dog::printIdeas( void )
{
	this->_brain->printIdeas();
}

void	Dog::printAnSpecificIdea( int ideaNumber )
{
	this->_brain->printAnSpecificIdea(ideaNumber);
}
