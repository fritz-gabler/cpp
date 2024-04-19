/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:49:02 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/18 15:49:56 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

Cat::Cat( void )
{
	this->_type = "Cat";
	this->_brain = new Brain;
	std::cout << "[ CAT ] Default constructor called" << std::endl;
}

Cat::Cat( const Cat &other )
{
	this->_type = other._type;
	this->_brain = new Brain(*(other._brain));
	std::cout << "[ CAT ] Copy constructor called" << std::endl;
}

Cat &Cat::operator = (const Cat &other)
{
	if (this != &other)
	{
		*(this->_brain) = *(other._brain);
		this->_type = other._type;
	}
	std::cout << "[ CAT ] Copy assignment constructor called" << std::endl;
	return (*this);
}

Cat::~Cat( void )
{
	delete _brain;
	std::cout << "[ CAT ] Destructor called" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void	Cat::makeSound( void ) const
{
	std::cout << "An usual cat sound: Miauuuu" << std::endl;
}

void	Cat::saveNewIdea( const std::string &idea )
{
	this->_brain->saveNewIdea(idea);
}

void	Cat::changeAnIdea( const std::string &idea, int ideaNumber )
{
	this->_brain->changeAnIdea(idea, ideaNumber);
}

void	Cat::printIdeas( void ) const
{
	this->_brain->printIdeas();
}

void	Cat::printAnSpecificIdea( int ideaNumber )
{
	this->_brain->printAnSpecificIdea(ideaNumber);
}
