/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:21:04 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/29 18:29:55 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int	main(int ac, char **av)
{
	Input	input;
	File	file;

	setupStruct(input, ac, av);
	inptCheck(input);
	file.openFile(input);
	while(input.process->status == RunLoop)
	{
		file.readLineFromFile(input);
		return (0);
	}
	return (0);
}
