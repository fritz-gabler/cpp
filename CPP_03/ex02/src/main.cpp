/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:52:57 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/12 11:37:58 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int	main(void)
{
	ClapTrap	clappy("Clappy");
	ClapTrap	enemy("Enemy");
	ScavTrap	superMan("Suberman");

	for (int i = 0; i < 11; i++)
	{
		clappy.attack("Enemy");
		enemy.takeDamage(5);
	}
	superMan.guardGate();
	superMan.guardGate();
	enemy.beRepaired(3);
	return (0);
}
