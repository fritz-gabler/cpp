/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:52:57 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/11 16:59:35 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int	main(void)
{
	ClapTrap clappy("Clappy");
	ClapTrap enemy("Enemy");

	clappy.attack("Enemy");
	enemy.takeDamage(5);
	enemy.beRepaired(3);

	return (0);
}
