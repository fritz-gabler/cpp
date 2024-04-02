/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:31:42 by fgabler           #+#    #+#             */
/*   Updated: 2024/04/02 13:35:41 by fgabler          ###   ########.fr       */
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
	int	caseLevel;

	identifyLevel(level, caseLevel);

	switch(caseLevel)
	{
		case DEBUG:
			debug();
		case INFO:
			info();
		case WARNING:
			warning();
		case ERROR:
			error();
			break ;
		default:
			printErrorMessage(DEFAULT_MESSAGE);
	}
}

