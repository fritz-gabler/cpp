/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WaitTillInput.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:51:15 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/12 12:16:17 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

static void	scanForExitMessage(std::string input, Process &process);

void	WaitTillInput(Process &process)
{
	std::string		input;

	if (process.Status == Exit)
		return ;
	process.Status = Start;
	while (process.process != Exit && process.Status != ColseContact)
	{
		std::cout << "To Close enter y: ";
		getStringSave(input, process);
		scanForExitMessage(input, process);
		process.PrintedLines += 1;
	}
}

static void	scanForExitMessage(std::string input, Process &process)
{
	if (input.compare("y") == 0 && input.length() == 1)
	{
		process.Status = ColseContact;
		return ;
	}
	std::cout << "Wrong Input\n";
	process.PrintedLines += 1;
}
