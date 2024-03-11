/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:06:26 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/11 11:11:41 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

PhoneBook::PhoneBook(void)
{
	numberOfContacts = 0;
	indexOfContact = 0;
}

void	PhoneBook::AddNewContact(int	*LinesPrinted)
{
	std::cout << NEW_CONTACT;
	*LinesPrinted += 1;
	ResetNumber();
	GetFirstName(LinesPrinted);
	GetLastName(LinesPrinted);
	GetNickName(LinesPrinted);
	GetPhoneNumber(LinesPrinted);
	GetDarkestSecret(LinesPrinted);
	SetNumber();
}

void	PhoneBook::ResetNumber(void)
{
	if (numberOfContacts > 7)
		numberOfContacts = 7;
	if (indexOfContact > 7)
		indexOfContact = 0;
}

void	PhoneBook::SetNumber(void)
{
		numberOfContacts++;
		indexOfContact++;
}

void	PhoneBook::GetFirstName(int *LinesPrinted)
{
	std::string		FirstName;

	std::cout << "First name: ";
	*LinesPrinted += 1;
	std::getline(std::cin, FirstName);
	if (IsString(FirstName) == true)
		contact[indexOfContact].AddFirstName(FirstName);
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
		contact[indexOfContact].AddLastName(LastName);
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
		contact[indexOfContact].NickNameAdd(NickName);
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
		contact[indexOfContact].PhoneNumberAdd(PhoneNumber);
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
		contact[indexOfContact].AddDarkestSecret(DarkesSecret);
	else
	{
		std::cout << RED << WRONG_NUMBER;
		std::cout << RESET;
		*LinesPrinted += 1;
		GetDarkestSecret(LinesPrinted);
	}
}

bool	PhoneBook::ContactExist()
{
	if (numberOfContacts > 0)
		return (true);
	return (false);
}

void	PhoneBook::SearchContact(int &linesPrinted)
{
	DisplayContactSnippet(linesPrinted);
	DisplaySpecificContact(linesPrinted);
	WaitTillInput(linesPrinted);
}

void	PhoneBook::DisplayContactSnippet(int &linesPrinted)
{
	int				i;

	i = 0;
	while (i < numberOfContacts)
	{
		contact[i].DisplayContactSnippet(i);
		linesPrinted += 4;
		i++;
	}
}

void	PhoneBook::DisplaySpecificContact(int &linesPrinted)
{
	int		Number;
	GetValidContactNumber(Number, linesPrinted);
	contact[Number].DisplayAllConatctData();
	linesPrinted += 7;
}

void	PhoneBook::GetValidContactNumber(int &Number, int &LinesPrinted)
{
	std::string	input;
	int			inputNumber;

	std::cout << "Please enter the contact index your searching for: ";
	LinesPrinted += 1;
	std::getline(std::cin, input);
	convertStringToInt(input, inputNumber);
	if (isValidContactNumber(inputNumber, numberOfContacts) == false)
	{
		std::cout << "Contact number does not exist or invalid input\n";
		LinesPrinted += 1;
		GetValidContactNumber(Number, LinesPrinted);
	}
	else
		Number = inputNumber;
}
