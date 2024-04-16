/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:52:57 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/12 13:31:21 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int	main(void)
{
	FragTrap	fraggy("fraggy");

	fraggy.takeDamage(110);
	fraggy.takeDamage(110);
	fraggy.highFivesGuys();
	fraggy.beRepaired(3);
	return (0);
}
