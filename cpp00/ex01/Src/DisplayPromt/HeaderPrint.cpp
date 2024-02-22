/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeaderPrint.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:01:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/22 11:57:15 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	HeaderPrint(void)
{
	std::cout << WHITE;
	std::cout << "/‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\\\n";
	std::cout << "|" << MAGENTA;
	std::cout << "         _____________________________________         ";
	std::cout << RESET << "|\n|" << MAGENTA;
	std::cout << "         |WELCOME TO YOUR PERSONAL PHONE BOOK|         ";
	std::cout << RESET << "|\n|" << MAGENTA;
	std::cout << "         ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾          ";
	std::cout << RESET << WHITE << "|\n|";
	std::cout << "                                                       ";
	std::cout << RESET << "|\n|" << RED;
	std::cout << "      ___________________________________________      ";
	std::cout << RESET << "|\n|" << RED;
	std::cout << "      |                 Manual                  |      ";
	std::cout << RESET << "|\n|" << RED;
	std::cout << "      |                                         |      ";
	std::cout << RESET << "|\n|" << RED;
	std::cout << "      |  ADD:    save a new contact             |      ";
	std::cout << RESET << "|\n|" << RED;
	std::cout << "      |                                         |      ";
	std::cout << RESET << "|\n|" << RED;
	std::cout << "      |  SEARCH: display a specific contact     |      ";
	std::cout << RESET << "|\n|" << RED;
	std::cout << "      |                                         |      ";
	std::cout << RESET << "|\n|" << RED;
	std::cout << "      |  EXIT:   the program quits              |      ";
	std::cout << RESET << "|\n|" << RED;
	std::cout << "      |                                         |      ";
	std::cout << RESET << "|\n|" << RED;
	std::cout << "       ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾      ";
	std::cout << RESET << "|\n";
	std::cout << "\\_______________________________________________________/\n\n";
}
