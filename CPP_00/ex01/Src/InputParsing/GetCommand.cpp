/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetCommand.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:45:59 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/10 11:42:39 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

void	GetInput(Process *Process);
void	CapitaliceInput(Process *Process);
void	SpecifyCommand(Process *Process);

void	GetCommand(Process *Process)
{
	GetInput(Process);
	CapitaliceInput(Process);
	SpecifyCommand(Process);
}

void	GetInput(Process *Process)
{
	std::cout << "Please enter a valid command\n:";
	Process->PrintedLines += 2;
	std::getline(std::cin, (*Process).Input);
}

void	CapitaliceInput(Process *Process)
{
	int		i;

	i = 0;
	while(Process->Input[i] != '\0')
	{
		Process->Input[i] = std::toupper(Process->Input[i]);
		i++;
	}
}

void	SpecifyCommand(Process *Process)
{
	if (Process->Input.compare("EXIT") == 0 && Process->Input.length() == 4)
		(*Process).Status = Exit;
	else if (Process->Input.compare("SEARCH") == 0
			&& Process->Input.length() == 6)
		(*Process).Status = Search;
	else if (Process->Input.compare("ADD") == 0 && Process->Input.length() == 3)
		(*Process).Status = Add;
	else
		(*Process).Status = FalseInput;
}
