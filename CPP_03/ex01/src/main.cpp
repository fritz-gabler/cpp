/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:52:57 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/12 11:50:37 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int	main(void)
{
	ScavTrap	superMan("Suberman");

	for (int i = 0; i < 11; i++)
	{
		superMan.attack("Enemy");
		superMan.takeDamage(5);
	}
	superMan.beRepaired(3);
	superMan.guardGate();
	superMan.guardGate();
	return (0);
}
