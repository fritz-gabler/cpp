/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:52:57 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/15 14:02:34 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int	main(void)
{
	DiamondTrap	diamondy("Diamondy");

	for (int i = 0; i < 31; i++)
	{
		diamondy.attack("Enemy");
		diamondy.takeDamage(5);
	}
	diamondy.highFivesGuys();
	diamondy.beRepaired(3);
	return (0);
}
