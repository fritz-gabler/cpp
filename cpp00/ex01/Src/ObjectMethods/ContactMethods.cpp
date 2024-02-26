/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactMethods.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:13:36 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/26 12:30:20 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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

void	Contact::print(void)
{
	std::cout << firstName << std::endl;
	std::cout << lastName << std::endl;
	std::cout << nickName << std::endl;
	std::cout << phoneNumber << std::endl;
	std::cout << darkestSecret << std::endl;
}
