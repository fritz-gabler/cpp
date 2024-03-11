/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetAction.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:06:19 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/11 14:06:01 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

static void	SetSearch(PhoneBook &phoneBook, Process &process);

void	SetAction(PhoneBook &phoneBook, Process &process)
{
	if (process.Status == Exit)
		return ;
	else if (process.Status == Add)
		phoneBook.AddNewContact(process);
	else if (process.Status == Search)
		SetSearch(phoneBook, process);
}

static void	SetSearch(PhoneBook &phoneBook, Process &process)
{
	if (phoneBook.ContactExist() == false)
		process.Status = NoContact;
	else
		phoneBook.SearchContact(process);
}
