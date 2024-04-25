/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:26:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/25 20:12:53 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

FragTrap::FragTrap( void )
{
	this->_name = "Karl";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "[ Frag Trap ] Default constructor called" << std::endl;
}

FragTrap::FragTrap( const std::string name )
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "[ Frag Trap ] Constructor with parameters called" << std::endl;
}

FragTrap::FragTrap( const FragTrap &other ) :
	ClapTrap(other)
{
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "[ Frag Trap ] Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator = ( const FragTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "[ Frag Trap ] Copy assignment constructor called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap( void )
{
	std::cout << "[ Frag Trap ] Destructor called" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void	FragTrap::highFivesGuys( void )
{
	std::cout << "Give me some skin! You're crushing it! High five!\n";
}
