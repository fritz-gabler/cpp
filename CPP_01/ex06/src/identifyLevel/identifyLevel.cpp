/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifyLevel.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:14:08 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/02 13:39:13 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void	identifyLevel(std::string level, int &caseLevel)
{
	int					i;
	const std::string	levelName[4] =
	{
		 "DEBUG",
		 "INFO",
		 "WARNING",
		 "ERROR"
	};
	
	i = 0;
	caseLevel = -1;
	while (i < 4)
	{
		if (levelName[i].compare(level) == sameLevel)
		{
			caseLevel = i;
			return ;
		}
		i++;
	}
}
