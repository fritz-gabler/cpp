/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IsString.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:11:39 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/24 18:05:46 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	IsString(std::string str)
{
	int		i;

	i = 0;
	while(str[i] != '\0')
	{
		if (std::isalpha(str[i]) == false && str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}
