/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:22:55 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/12 11:40:59 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

ScavTrap::ScavTrap( void )
{
		this->_name = "Karl";
		this->_hitPoints = 100;
		this->_energyPoints = 50;
		this->_attackDamage = 20;
		this->_isProtecting = false;
		std::cout << "[ Scav Trap ] Default constructor called" << std::endl;
}

ScavTrap::ScavTrap( const std::string name )
{
        this->_name = name;
		this->_hitPoints = 100;
		this->_energyPoints = 50;
		this->_attackDamage = 20;
		this->_isProtecting = false;
		std::cout << "[ Scav Trap ] Constructor with parameters called" << std::endl;
}

ScavTrap &ScavTrap::operator = ( const ScavTrap &other)
{
		if (this != &other)
		{
				this->_name = other._name;
				this->_hitPoints = other._hitPoints;
				this->_energyPoints = other._energyPoints;
				this->_attackDamage = other._attackDamage;
		}
		std::cout << "[ Scav Trap ] Copy constructor called" << std::endl;
		return (*this);
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "[ Scav Trap ] Destructor called" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void	ScavTrap::guardGate( void )
{
	this->_isProtecting = !this->_isProtecting;
	std::cout << "Guard is called and that he is protecting is now ";
	if (this->_isProtecting == true)
		std::cout << "true\n";
	else
		std::cout << "false\n";
}
