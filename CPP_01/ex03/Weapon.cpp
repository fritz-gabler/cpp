/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:30:31 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/10 14:10:08 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string	&Weapon::getType(void)
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}

Weapon::Weapon(void)
{
	_type = "only rhetorical skill";
}

Weapon::Weapon(std::string type)
{
	_type = type;
}

Weapon::~Weapon(void) {}
