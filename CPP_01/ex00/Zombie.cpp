/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:00:45 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/08 10:02:26 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	_name = "Anonym";
}

Zombie::Zombie(std::string NewZombieName)
{
	_name = NewZombieName;
}
Zombie::~Zombie(void)
{
	std::cout
			<< _name
			<< ": says farewell and dies"
			<< std::endl;
}

void	Zombie::announce(void)
{
	std::cout
			<< _name
			<< ": BraiiiiiiinnnzzzZ..."
			<< std::endl;
}
