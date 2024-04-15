/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:52:57 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/12 13:22:53 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int	main(void)
{
	FragTrap	fraggy("fraggy");

	for (int i = 0; i < 31; i++)
	{
		fraggy.attack("Enemy");
		fraggy.takeDamage(5);
	}
	fraggy.highFivesGuys();
	fraggy.beRepaired(3);
	return (0);
}
