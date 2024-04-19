/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:46:25 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/18 19:14:56 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

Brain::Brain( void )
{
	this->_currentIdeaNumber = 0;
	std::cout << "[ BRAIN ] Default constructor called" << std::endl;
}

Brain::Brain( const Brain &other )
{
	for (int i = 0; i < BRAIN_CAPACITY ; i++)
		this->_ideas[i] = other._ideas[i];
	std::cout << "[ BRAIN ] Copy constructor called" << std::endl;
}

Brain &Brain::operator = ( const Brain &other )
{
	if (this != &other)
	{
		for (int i = 0; i < BRAIN_CAPACITY ; i++)
			this->_ideas[i] = other._ideas[i];
	}
	std::cout << "[ BRAIN ] Copy assignment constructor called" << std::endl;
	return (*this);
}

Brain::~Brain( void )
{
	std::cout << "[ BRAIN ] Destructor called" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void	Brain::saveNewIdea( const std::string &idea )
{
	if (this->_currentIdeaNumber > (BRAIN_CAPACITY - 1))
		this->_currentIdeaNumber = 0;
	this->_ideas[this->_currentIdeaNumber] = idea;
	this->_currentIdeaNumber += 1;
}

void	Brain::changeAnIdea( const std::string &idea, int ideaNumber )
{
	if (inBrainCapacityRange(ideaNumber) == false)
		return ;
	this->_ideas[ideaNumber] = idea;
}

void	Brain::printIdeas( void )
{
	for ( int i = 0; i < BRAIN_CAPACITY ; i++)
	{
		std::cout << "Idea Number ["
				<< i
				<< "] "
				<< this->_ideas[i]
				<< std::endl;
	}
}

void	Brain::printAnSpecificIdea( int ideaNumber )
{
	if (inBrainCapacityRange(ideaNumber) == false)
		return ;
	std::cout << "Idea Number["
		<< ideaNumber
		<< "] "
		<< this->_ideas[ideaNumber]
		<< std::endl;
}
