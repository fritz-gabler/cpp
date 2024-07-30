/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_action.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:06:19 by fgabler           #+#    #+#             */
/*   Updated: 2024/07/30 14:12:06 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

static void	set_search(PhoneBook &phoneBook, Process &process);

void	set_action(PhoneBook &phoneBook, Process &process)
{
	if (process.Status == Exit)
		return ;
	else if (process.Status == Add)
		phoneBook.AddNewContact(process);
	else if (process.Status == Search)
		set_search(phoneBook, process);
}

static void	set_search(PhoneBook &phoneBook, Process &process)
{
	if (phoneBook.ContactExist() == false)
		process.Status = NoContact;
	else
		phoneBook.SearchContact(process);
}
