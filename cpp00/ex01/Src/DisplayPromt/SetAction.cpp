/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetAction.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:06:19 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/22 18:16:15 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	SetAction(PhoneBook *PhoneBook, Process *Process)
{
	if (Process->Status == Exit)
		return ;
	else if (Process->Status == Add)
		PhoneBook->AddNewContact(&Process->PrintedLines);
	else if (Process->Status == Search)
		std::cout << "function is coming" << std::endl;
}
