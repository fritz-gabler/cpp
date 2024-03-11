/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:06:26 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/11 14:36:27 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

PhoneBook::PhoneBook(void)
{
	numberOfContacts = 0;
	indexOfContact = 0;
}

void	PhoneBook::AddNewContact(Process &process)
{
	std::cout << NEW_CONTACT;
	process.PrintedLines += 1;
	ResetNumber();
	GetFirstName(process);
	GetLastName(process);
	GetNickName(process);
	GetPhoneNumber(process);
	GetDarkestSecret(process);
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

void	PhoneBook::GetFirstName(Process &process)
{
	std::string		FirstName;

	if (process.Status == Exit)
		return ;
	std::cout << "First name: ";
	process.PrintedLines += 1;
	getStringSave(FirstName, process);
	if (IsString(FirstName) == true)
		contact[indexOfContact].AddFirstName(FirstName);
	else
	{
		std::cout << RED
				<< "Wrong input, enter a real name. Try again\n"
				<< RESET;
		process.PrintedLines += 1;
		GetFirstName(process);
	}
}

void	PhoneBook::GetLastName(Process &process)
{
	std::string		LastName;

	if (process.Status == Exit)
		return ;
	std::cout << "Last name: ";
	process.PrintedLines += 1;
	getStringSave(LastName, process);
	if (IsString(LastName) == true)
		contact[indexOfContact].AddLastName(LastName);
	else
	{
		std::cout << RED
				<< "Wrong input, enter a real last name. Try again\n" << RESET;
		process.PrintedLines += 1;
		GetLastName(process);
	}
}

void	PhoneBook::GetNickName(Process &process)
{
	std::string		NickName;

	if (process.Status == Exit)
		return ;
	std::cout << "Nickname: ";
	process.PrintedLines += 1;
	getStringSave(NickName, process);
	if (IsString(NickName) == true)
		contact[indexOfContact].NickNameAdd(NickName);
	else
	{
		std::cout << RED << "Wrong input. Try again\n" << RESET;
		process.PrintedLines += 1;
		GetNickName(process);
	}
}

void	PhoneBook::GetPhoneNumber(Process &process)
{
	std::string		PhoneNumber;

	if (process.Status == Exit)
		return ;
	std::cout << "Phone number: ";
	process.PrintedLines += 1;
	getStringSave(PhoneNumber, process);
	if (ValidePhoneNumber(PhoneNumber) == true)
		contact[indexOfContact].PhoneNumberAdd(PhoneNumber);
	else
	{
		std::cout << RED << WRONG_NUMBER;
		std::cout << RESET;
		process.PrintedLines += 2;
		GetPhoneNumber(process);
	}
}

void	PhoneBook::GetDarkestSecret(Process &process)
{
	std::string		DarkesSecret;

	if (process.Status == Exit)
		return ;
	std::cout << "Darkest Secret: ";
	process.PrintedLines += 1;
	getStringSave(DarkesSecret, process);
	if (IsString(DarkesSecret) == true)
		contact[indexOfContact].AddDarkestSecret(DarkesSecret);
	else
	{
		std::cout << RED << WRONG_NUMBER;
		std::cout << RESET;
		process.PrintedLines += 1;
		GetDarkestSecret(process);
	}
}

bool	PhoneBook::ContactExist()
{
	if (numberOfContacts > 0)
		return (true);
	return (false);
}

void	PhoneBook::SearchContact(Process &process)
{
	DisplayContactSnippet(process);
	DisplaySpecificContact(process);
	WaitTillInput(process);
}

void	PhoneBook::DisplayContactSnippet(Process &process)
{
	int				i;

	i = 0;
	if (process.Status == Exit)
		return ;
	while (i < numberOfContacts)
	{
		contact[i].DisplayContactSnippet(i);
		process.PrintedLines += 4;
		i++;
	}
}

void	PhoneBook::DisplaySpecificContact(Process &process)
{
	int		Number;

	GetValidContactNumber(Number, process);
	if (process.Status == Exit)
		return ;
	contact[Number].DisplayAllConatctData();
	process.PrintedLines += 7;
}

void	PhoneBook::GetValidContactNumber(int &Number, Process &process)
{
	std::string	input;
	int			inputNumber;

	if (process.Status == Exit)
		return ;
	std::cout << "Please enter the contact index your searching for: ";
	process.PrintedLines += 1;
	getStringSave(input, process);
	convertStringToInt(input, inputNumber);
	if (isValidContactNumber(inputNumber, numberOfContacts, process) == false)
	{
		std::cout << "Contact number does not exist\n";
		process.PrintedLines += 1;
		GetValidContactNumber(Number, process);
	}
	else
		Number = inputNumber;
}
