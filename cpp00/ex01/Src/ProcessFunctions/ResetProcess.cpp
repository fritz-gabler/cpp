/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ResetProcess.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:41:13 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/25 21:05:04 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	ResetProcess(Process *Process)
{
	if (Process->Status == FalseInput)
	{
		std::cout << RED << "Wrong input. Take a look at the manual\n" << RESET;
		Process->PrintedLines = 1;
	}
	else if (Process->Status == Add)
	{
		std::cout << GRASS_GREEN << "Contact added √\n" << RESET;
		Process->PrintedLines = 1;
	}
	else if (Process->Status == NoContact)
	{
		std::cout << RED << NO_CONTACT;
		std::cout << RESET;
		Process->PrintedLines = 1;
	}
	else
		Process->PrintedLines = 0;
}

