/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:41:01 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/15 13:50:54 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

DiamondTrap::DimondTrap( void ) : ClapTrap(), FragTrap(), ScavTrap()
{
	this->_name = "Karl";
	this->ClapTrap::_name = "Kalr" + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "[ Dimond Trap ] Default constructor called: "
		<< this->_name
		<< std::endl;
}


DiamondTrap::DimondTrap( const std::string name )
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "[ Diamond Trap ] Constructor with parameters called: "
		<< name
		<< std::endl;
}

DiamondTrap::DimondTrap( const DiamondTrap &other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	*this->other;
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
		this->_energyPoints = other._eneryPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "[ Diamond Trap ] Copy constructor called: "
		<< other._name
		<< std::endl;
	return (*this);
}

~DiamondTrap( void )
{
	std::cout << "[ Diamond Trap ] Destructor called";
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
	std::cout << "May I introduce myself, my name is "
		<< this->_name
		<< ", and my great-grandfather is class ClapTrap, his name is"
		<< ClapTrap::_name
		<< std::endl;
}
