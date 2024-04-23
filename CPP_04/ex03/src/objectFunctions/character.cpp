/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:54:48 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/23 10:58:37 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

Character::Character( void )
{
	this->_name = "Default Character";
	this->indexTrashBack = 0;
	for ( int i = 0 ; i < INVENTORY_VOLUME ; i++ )
	{
		this->_inventory[i] = NULL;
		this->_trashBack[i] = NULL;
	}
	//std::cout << "[ CHARACTER ] Default constructor called" << std::endl;
}

Character::Character( const Character &other )
{
	for ( int i = 0 ; i < INVENTORY_VOLUME ; i++)
	{
		this->_inventory[i] = NULL;
		this->_trashBack[i] = NULL;
	}
	*this = other;
	//std::cout << "[ CHARACTER ] Constructor with arguments called" << std::endl;
}

Character::Character( const std::string name)
{
	this->_name = name;
	for ( int i = 0 ; i < INVENTORY_VOLUME ; i++)
	{
		this->_inventory[i] = NULL;
		this->_trashBack[i] = NULL;
	}
}

Character &Character::operator = ( const Character &other )
{
	if (this == &other)
		return (*this);

	this->_name = other._name;
	this->indexTrashBack = other.indexTrashBack;
	for ( int i = 0 ; i < INVENTORY_VOLUME ; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		if (this->_trashBack[i] != NULL)
			delete this->_trashBack[i];
		this->_inventory[i] = NULL;
		this->_trashBack[i] = NULL;
	}
	//std::cout << "[ CHARACTER ] Copy assignment constructor called" << std::endl;
	return (*this);
}

Character::~Character( void )
{
	for ( int i = 0 ; i < INVENTORY_VOLUME ; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
		if (this->_trashBack[i] != NULL)
			delete this->_trashBack[i];
	}
	//std::cout << "[ CHARACTER ] Destructor called" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

std::string	&Character::getName( void ) const
{
	return (this->_name);
}

void		Character::equip(AMateria *materia)
{
	if (materia == NULL)
	{
		std::cout << INPUT_MATERIA_IS_NULL;
		return ;
	}

	for ( int i = 0 ; i < INVENTORY_VOLUME ; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = materia;
			return ;
		}
	}
	delete materia;
	std::cout << NO_SPACE_IN_INVENTORY;
}

void		Character::unequip(int index)
{
	if (index >= INVENTORY_VOLUME)
		std::cout << NOT_IN_INDEX_RANGE;
	else if ( this->_inventory[index] == NULL )
		std::cout << NO_MATERIA_AT_THAT_INDEX;
	else
	{
		saveMateria(index);
		this->_inventory[index] = NULL;
	}
}

void	Character::saveMateria( int index)
{
	if ( this->indexTrashBack == (INVENTORY_VOLUME) )
		indexTrashBack = 0;
	if ( this->_trashBack[indexTrashBack] != NULL)
		delete this->_trashBack[indexTrashBack];
	this->_trashBack[indexTrashBack] = this->_inventory[index];
	this->indexTrashBack++;
}

void	Character::use( int index, ICharacter &target )
{
	if (index >= (INVENTORY_VOLUME - 1) || index < 0 )
		std::cout << NOT_IN_INDEX_RANGE;
	else if (this->_inventory[index] == NULL)
		std::cout << NO_MATERIA_AT_THAT_INDEX;
	else
		this->_inventory[index]->use(target);
}
