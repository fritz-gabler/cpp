/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayContact.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 09:25:11 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/26 12:30:52 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	DisplayFeeld(std::string Content);
static void	LimitLenthCheck(std::string &Content);
static void	PrintSpaces(std::string Content);

void	Contact::DisplayContact(int ContactNumber)
{
	std::cout << "_________________________________________________________\n";
	std::cout << "|  INDEX  |  FIRST NAME  |   Last Name   |   Nickname   |\n";
	std::cout << "|    " << ContactNumber << "    |";
	DisplayFeeld(firstName);
	std::cout << ' ';
	DisplayFeeld(lastName);
	DisplayFeeld(nickName);
	std::cout << "\n‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n";
}

static void	DisplayFeeld(std::string Content)
{
	LimitLenthCheck(Content);
	//std::cout << "| ";
	PrintSpaces(Content);
	std::cout << Content;
	std::cout << " |";
}

static void	LimitLenthCheck(std::string &Content)
{
	if (Content.length() < 11)
		return ;
	Content[9] = '.';
	Content[10] = '\0';
}

static void	PrintSpaces(std::string Content)
{
	int		NumberOfSpaces;

	NumberOfSpaces = 10 - Content.length();
	while (NumberOfSpaces--)
		std::cout << ' ';
}
