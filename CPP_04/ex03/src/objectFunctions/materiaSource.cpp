/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materiaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:36:26 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/23 13:31:26 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

///////////////////////////////////////////////////////////////////////////////
////////////////////////////CONSTRUCTOR AND DESTRUCTOR/////////////////////////
///////////////////////////////////////////////////////////////////////////////

MateriaSource::MateriaSource( void )
{
	for ( int i = 0 ; i < INVENTORY_VOLUME ; i++ )
		this->_storage[i] = NULL;
	this->_usedStorage  = 0;
	//std::cout << "[ A MATERIA ] Default constructor called" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource &other )
{
	*this = other;
}

MateriaSource &MateriaSource::operator = ( const MateriaSource &other )
{
	if (this == &other)
		return (*this);
	for ( int i = 0 ; i < INVENTORY_VOLUME ; i++ )
	{
		if (this->_storage[i] != NULL)
		{
			delete this->_storage[i];
			this->_storage[i] = NULL;
		}
		if (other._storage[i] != NULL)
			this->_storage[i] = other._storage[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource( void )
{
	for ( int i = 0 ; i < INVENTORY_VOLUME ; i++ )
	{
		if (this->_storage[i] != NULL)
		{
			delete this->_storage[i];
			this->_storage[i] = NULL;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
////////////////////////////////MEMBER FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void	MateriaSource::learnMateria(AMateria *materia)
{
	if (MateriaSource::inputCheckLearn(materia) == false)
		return ;
	this->_usedStorage++;
	this->_storage[this->_usedStorage] = materia;
	return ;
}

bool	MateriaSource::inputCheckLearn( AMateria *materia )
{
	if (materia == NULL)
	{
		std::cout << MATERIA_IS_NULL;
		return (false);
	}
	else if (this->_usedStorage == (INVENTORY_VOLUME - 1) )
	{
		std::cout << NO_SPACE_IN_INVENTORY;
		return (false);
	}
	return (true);
}

AMateria	*MateriaSource::createMateria( const std::string &type )
{
	for ( int i = 0 ; i < INVENTORY_VOLUME ; i++ )
	{
		if (this->_storage[i] != NULL && this->_storage[i]->getType() == type)
			return (this->_storage[i]->clone());
	}
	return (NULL);
}
