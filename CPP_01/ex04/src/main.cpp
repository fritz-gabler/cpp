/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:21:04 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/19 16:32:12 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int	main(int ac, char **av)
{
	Input	input;

	setupStruct(input, ac, av);
	inptCheck(input);
	while(input.process->status == RunLoop)
	{
		
	}
	return (0);
}
