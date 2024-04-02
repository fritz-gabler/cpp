/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputCheck.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:44:55 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/02 13:36:05 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

//static bool	correctLevelNames(std::string level);

bool	correctInput(int ac)
{
	if (ac != 2)
		return (printErrorMessage(WRONG_NB_OF_ARGS), false);
	return (true);
}

/*
static bool	correctLevelNames(std::string level)
{
	int	i;
	const std::string	levelNames[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	i = 0;
	while (i < 4)
	{
		if (levelNames[i].compare(level) == sameLevel)
			return (true);
		i++;
	}
	printErrorMessage(WRONG_LEVEL_NAME);
	return (false);
}
*/
