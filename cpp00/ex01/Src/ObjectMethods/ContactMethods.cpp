/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactMethods.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:13:36 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/26 11:49:13 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	Contact::AddFirstName(std::string Input)
{
		FirstName = Input;
}

void	Contact::AddLastName(std::string Input)
{
	LastName = Input;
}

void	Contact::NickNameAdd(std::string Input)
{
	NickName = Input;
}

void	Contact::PhoneNumberAdd(std::string Input)
{
	PhoneNumber = Input;
}

void	Contact::AddDarkestSecret(std::string Input)
{
	DarkestSecret = Input;
	print();
}

void	Contact::print(void)
{
	std::cout << FirstName << std::endl;
	std::cout << LastName << std::endl;
	std::cout << NickName << std::endl;
	std::cout << PhoneNumber << std::endl;
	std::cout << DarkestSecret << std::endl;
}
