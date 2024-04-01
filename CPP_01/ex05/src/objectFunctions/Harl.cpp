/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:31:42 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/01 16:00:09 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

void	Harl::debug( void )
{
	std::cout
			<< "[ DEBUG ]"
			<< std::endl
			<< DEBUG_MESSAGE
			<< std::endl;
}

void	Harl::info( void )
{
	std::cout
			<< "[ INFO ]"
			<< std::endl
			<< INFO_MESSAGE
			<< std::endl;
}

void	Harl::warning( void )
{
	std::cout
			<< "[ WARNING ]"
			<< std::endl
			<< WARNING_MESSAGE
			<< std::endl;
}

void	Harl::error( void )
{
	std::cout
			<< "[ ERROR ]"
			<< std::endl
			<< ERROR_MESSAGE
			<< std::endl;
}

void	Harl::complain(std::string level)
{
	void				(Harl::*ptrToMemberFunctions[4]) () =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	const std::string	levelName[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	int					i;

	i = 0;
	while (i < 4)
	{
		if (levelName[i].compare(level) == sameLevel)
			(this->*ptrToMemberFunctions[i]) ();
		i++;
	}
}

