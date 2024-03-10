/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:48:00 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/10 15:05:31 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack(void)
{
	std::cout
		<< _name
		<< " attacks with their "
		<< _weapon.getType()
		<< std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon)
	:_name(name), _weapon(weapon) {};
