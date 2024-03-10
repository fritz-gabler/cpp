/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WaitTillInput.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:51:15 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/10 11:44:27 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

void	WaitTillInput(int &LinesPrinted)
{
	int				status;
	std::string		input;

	status = Start;
	while (status != Exit)
	{
		std::cout << "To Close enter y: ";
		std::getline(std::cin, input);
		if (input.compare("y") == 0 && input.length() == 1)
			status = Exit;
		else
		{
			std::cout << "Wrong Input\n";
			LinesPrinted += 1;
		}
		LinesPrinted += 1;
	}
}
