/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeaderPrint.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:01:44 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/10 11:39:02 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

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
	std::cout << RESET << "|\n|" << GRASS_GREEN;
	std::cout << "      ___________________________________________      ";
	std::cout << RESET << "|\n|" << GRASS_GREEN;
	std::cout << "      |                 Manual                  |      ";
	std::cout << RESET << "|\n|" << GRASS_GREEN;
	std::cout << "      |                                         |      ";
	std::cout << RESET << "|\n|" << GRASS_GREEN;
	std::cout << "      |  ADD:    save a new contact             |      ";
	std::cout << RESET << "|\n|" << GRASS_GREEN;
	std::cout << "      |                                         |      ";
	std::cout << RESET << "|\n|" << GRASS_GREEN;
	std::cout << "      |  SEARCH: display a specific contact     |      ";
	std::cout << RESET << "|\n|" << GRASS_GREEN;
	std::cout << "      |                                         |      ";
	std::cout << RESET << "|\n|" << GRASS_GREEN;
	std::cout << "      |  EXIT:   the program quits              |      ";
	std::cout << RESET << "|\n|" << GRASS_GREEN;
	std::cout << "      |                                         |      ";
	std::cout << RESET << "|\n|" << GRASS_GREEN;
	std::cout << "       ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾      ";
	std::cout << RESET << "|\n";
	std::cout << "\\_______________________________________________________/\n";
	std::cout << std::endl;
}
