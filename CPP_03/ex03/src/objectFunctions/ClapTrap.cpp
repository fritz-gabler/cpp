/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:39:12 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/15 19:29:57 by fgabler          ###   ########.fr       */
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
	std::cout << "ClapTrap Name: " << &this->_name << std::endl;
	std::cout << "Content Name: " << this->_name << std::endl;
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

ClapTrap &ClapTrap::operator = ( const ClapTrap &other)
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
		std::cout << "ClapTrap "
			<< this->_name
			<< " attacks "
			<< target
			<< ", causing "
			<< this->_attackDamage
			<< " points of damage!"
			<< std::endl;
		this->_energyPoints--;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap "
			<< this->_name
			<< " wants to attack but ain't got energy left"
			<< std::endl;
	}
	else if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap "
			<< this->_name
			<< " wants to attack but ain't got strength to move a finger"
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
				<< " gets brutally attacked and has no health left!"
				<< std::endl;
		}
	}
	else
	{
		std::cout << "ClapTrap "
			<< "please have mercy, "
			<< this->_name
			<< " is already dead"
			<< std::endl;
	}
}

	void	ClapTrap::beRepaired( unsigned int amount )
	{
		if (_energyPoints > 0 && _hitPoints > 0)
		{
			std::cout << "ClapTrap "
			<< this->_name
			<< " repairs itself, gaining "
			<< amount
			<< " hit points!"
			<< std::endl;
			this->_hitPoints += amount;
			this->_energyPoints -= 1;
		}
		else
		{
			std::cout << "Many have attempted "
				<< "to reverse death in order to bring "
				<< this->_name 
				<< " back to life, but greater miracles must "
				<< "occur than just the mere attempt of healing."
				<< std::endl;
		}
	}
