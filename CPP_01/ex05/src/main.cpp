/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:31:08 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/01 16:03:16 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int	main(int ac, char **av)
{
	Harl	harl;

	if (correctInput(ac, av) == false)
		return (1);
	harl.complain(av[1]);
	return (0);
}
