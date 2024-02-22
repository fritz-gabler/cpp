/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetCommand.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:45:59 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/22 11:49:57 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/PhoneBook.hpp"

void	GetInput(Process *Process);

void	GetCommand(Process *Process)
{
	GetInput(Process);
}

void	GetInput(Process *Process)
{
	std::cout << "Please enter a valid command\n:";
	std::cin >> *Process.Input;
}

void	SpecifyCommand(Process *Process)
{
	std::string		test;
	
	if (Process.)
}
