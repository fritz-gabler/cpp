/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:23:38 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/10 12:00:22 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

void	Contact::AddFirstName(std::string Input)
{
	firstName = Input;
}

void	Contact::AddLastName(std::string Input)
{
	lastName = Input;
}

void	Contact::NickNameAdd(std::string Input)
{
	nickName = Input;
}

void	Contact::PhoneNumberAdd(std::string Input)
{
	phoneNumber = Input;
}

void	Contact::AddDarkestSecret(std::string Input)
{
	darkestSecret = Input;
}

void	Contact::DisplayContactSnippet(int ContactNumber)
{
	std::cout << "_____________________________________________\n";
	std::cout << "|";
	//DisplayFeeld(ContactNumber);
	DisplayFeeldStr("INDEX");
	DisplayFeeldStr("FIRST NAME");
	DisplayFeeldStr("LAST NAME");
	DisplayFeeldStr("NICKNAME");
	std::cout << std::endl;
	std::cout << "|";
	DisplayFeeldInt(ContactNumber);
	DisplayFeeldStr(firstName);
	DisplayFeeldStr(lastName);
	DisplayFeeldStr(nickName);
	std::cout << "\n‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n";
}

void	Contact::DisplayAllConatctData(void)
{
	std::cout << "\n";
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
	std::cout << "\n";
}
