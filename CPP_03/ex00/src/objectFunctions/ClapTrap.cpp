/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:39:12 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/11 15:59:52 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

ClapTrap::ClapTrap( void )
{
	this->_name = "Karl";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "[ Clap Trap ] Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( const std::string name )
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "[ Clap Trap ] Constructor with parameters called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &other )
{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	std::cout << "[ Clap Trap ] Copy constructor called" << std::endl;
}

ClapTrap ClapTrap::&operator = ( const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "[ Clap Trap ] Copy constructor called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "[ Clap Trap ] Destructor called" << std::endl;
}


///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void ClapTrap::attack( const std::string &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap"
			<< this->_name
			<< "attack "
			<< target
			<< ", causing "
			<< this->_attackDamage
			<< " points of damage!"
			<< std::endl;
		this->_hitPoints--;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap"
			<< this->_name
			<< "wants to attack but ain't got energy left"
			<< std::endl;
	}
	else if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap"
			<< this->_name
			<< "wants to attack but ain't got strength to move a finger"
			<< std::endl;
	}
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		if (amount < this->_hitPoints)
		{
			std::cout << "ClapTrap "
				<< this->_name
				<< " takes "
				<< amount
				<< " points of damage!"
				<< std::endl;
			this->_hitPoints -= amount;
		}
		else
		{
			this->_hitPoints = 0;
			std::cout << "ClapTrap "
				<< this->_name
				<< "gets brutally attacked and has no health left!"
				<< std::endl;
			_hitPoints -= amount;
		}
	}
	else
	{
			std::cout << "ClapTrap "
				<< "please have mercy, "
				<< this->_name
				<< "is already dead"
				<< std::endl;
	}
}

	void	ClapTrap::beRapaired( unsigned int amount )
	{
		if (_energyPoints > 0 && _hitPoints > 0)
		{
			std::cout << "ClapTrap <name> repairs itself, gaining "
			<< amount
			<< "hit points!"
			this->_hitPoints += amount;
			this->_energyPoints -= 1;
		}
		else
		{
			std::cout << "Many have attempted "
				<< "to reverse death in order to bring "
				<< this->_name 
				<< std::endl;
				<< " back to life, but greater miracles must "
				<< "occur than just the mere attempt of healing."
				<< std::endl;
		}
	}
