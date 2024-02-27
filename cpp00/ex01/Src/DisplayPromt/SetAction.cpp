/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetAction.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:06:19 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/27 12:46:53 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	SetSearch(PhoneBook *PhoneBook, Process *Process);

void	SetAction(PhoneBook *PhoneBook, Process *Process)
{
	if (Process->Status == Exit)
		return ;
	else if (Process->Status == Add)
		PhoneBook->AddNewContact(&Process->PrintedLines);
	else if (Process->Status == Search)
		SetSearch(PhoneBook, Process);
}

static void	SetSearch(PhoneBook *PhoneBook, Process *Process)
{
	if (PhoneBook->ContactExist() == false)
		Process->Status = NoContact;
	else
		PhoneBook->SearchContact(Process->PrintedLines);
}
