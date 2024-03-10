/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:02:41 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/10 16:05:34 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout
		<< _name
		<< " attacks with their "
		<< _weapon->getType()
		<< std::endl;
}

HumanB::HumanB(std::string name)
	:_name(name), _weapon(NULL) {}
