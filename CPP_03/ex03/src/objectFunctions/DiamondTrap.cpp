/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:41:01 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/16 14:45:40 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

DiamondTrap::DiamondTrap( void ) : ClapTrap(), FragTrap(), ScavTrap()
{
	this->_name = "Karl";
	this->ClapTrap::_name = "Kalr_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "[ Dimond Trap ] Default constructor called: "
		<< this->_name
		<< std::endl;
}


DiamondTrap::DiamondTrap( const std::string name )
	: ClapTrap(), FragTrap(), ScavTrap(name + "_clap_name")
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "[ Diamond Trap ] Constructor with parameters called: "
		<< name
		<< std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &other )
	: ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	*this= other;
	std::cout << "[ Diamond Trap ] Copy constructor called: "
		<< other._name
		<< std::endl;
}

DiamondTrap &DiamondTrap::operator = ( const DiamondTrap &other )
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "[ Diamond Trap ] Copy assignment constructor called: "
		<< other._name
		<< std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "[ Diamond Trap ] Destructor called\n";
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void	DiamondTrap::attack( const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << std::endl
		<< "May I introduce myself,"
		<< std::endl
		<< "my name is: "
		<< this->_name
		<< std::endl
		<< "and my great-grandfather is class ClapTrap,"
		<< std::endl
		<< "his name is: "
		<< ClapTrap::_name
		<< std::endl
		<< std::endl;
}
