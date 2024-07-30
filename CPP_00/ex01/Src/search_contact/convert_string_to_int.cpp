/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertStringToInt.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:35:24 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/11 11:09:18 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

static bool	isStringNumber(std::string string);

void	convertStringToInt(std::string string, int &convertedString)
{
	std::stringstream	tmpString;

	if (isStringNumber(string) == false)
		convertedString = -1;
	else
	{
		tmpString << string;
		tmpString >> convertedString;
	}
}

static bool	isStringNumber(std::string string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (std::isdigit(string[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}
