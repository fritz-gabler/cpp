/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AddNewContact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:28:36 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/26 11:59:11 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::AddNewContact(int	*LinesPrinted)
{
	std::cout << NEW_CONTACT;
	SetContactNumber();
	GetFirstName(LinesPrinted);
	GetLastName(LinesPrinted);
	GetNickName(LinesPrinted);
	GetPhoneNumber(LinesPrinted);
	GetDarkestSecret(LinesPrinted);
	*LinesPrinted += 2;
}

void	PhoneBook::SetContactNumber(void)
{
	if (NumberOfContacts > 7)
		NumberOfContacts = 0;
	else
		NumberOfContacts++;
}

void	PhoneBook::GetFirstName(int *LinesPrinted)
{
	std::string		FirstName;

	std::cout << "First name: ";
	*LinesPrinted += 1;
	std::getline(std::cin, FirstName);
	if (IsString(FirstName) == true)
		Contact[NumberOfContacts].AddFirstName(FirstName);
	else
	{
		std::cout << RED
				<< "Wrong input, enter a real name. Try again\n" << RESET;
		*LinesPrinted += 1;
		GetFirstName(LinesPrinted);
	}
}

void	PhoneBook::GetLastName(int *LinesPrinted)
{
	std::string		LastName;

	std::cout << "Last name: ";
	*LinesPrinted += 1;
	std::getline(std::cin, LastName);
	if (IsString(LastName) == true)
		Contact[NumberOfContacts].AddLastName(LastName);
	else
	{
		std::cout << RED
				<< "Wrong input, enter a real last name. Try again\n" << RESET;
		*LinesPrinted += 1;
		GetLastName(LinesPrinted);
	}
}

void	PhoneBook::GetNickName(int *LinesPrinted)
{
	std::string		NickName;

	std::cout << "Nickname: ";
	*LinesPrinted += 1;
	std::getline(std::cin, NickName);
	if (IsString(NickName) == true)
		Contact[NumberOfContacts].NickNameAdd(NickName);
	else
	{
		std::cout << RED << "Wrong input. Try again\n" << RESET;
		*LinesPrinted += 1;
		GetNickName(LinesPrinted);
	}
}

void	PhoneBook::GetPhoneNumber(int *LinesPrinted)
{
	std::string		PhoneNumber;

	std::cout << "Phone number: ";
	*LinesPrinted += 1;
	std::getline(std::cin, PhoneNumber);
	if (ValidePhoneNumber(PhoneNumber) == true)
		Contact[NumberOfContacts].PhoneNumberAdd(PhoneNumber);
	else
	{
		std::cout << RED << WRONG_NUMBER;
		std::cout << RESET;
		*LinesPrinted += 2;
		GetPhoneNumber(LinesPrinted);
	}
}

void	PhoneBook::GetDarkestSecret(int *LinesPrinted)
{
	std::string		DarkesSecret;

	std::cout << "Darkest Secret: ";
	*LinesPrinted += 1;
	std::getline(std::cin, DarkesSecret);
	if (IsString(DarkesSecret) == true)
		Contact[NumberOfContacts].AddDarkestSecret(DarkesSecret);
	else
	{
		std::cout << RED << WRONG_NUMBER;
		std::cout << RED << "Wrong input. Try again\n" << RESET;
		*LinesPrinted += 1;
		GetDarkestSecret(LinesPrinted);
	}
}

void	PhoneBook::print(void)
{
	int		i;

	i = 0;
	while (i != NumberOfContacts)
		Contact[i++].print();
}
