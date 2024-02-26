/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SearchContact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:06:14 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/26 12:27:29 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::SearchContact(int *LinesPrinted)
{
	int		i;

	i = 0;
	while (i < numberOfContacts)
	{
		contact[i].DisplayContact(i);
		*LinesPrinted += 4;
		i++;
	}
}

bool	PhoneBook::ContactExist()
{
	if (numberOfContacts > 0)
		return (true);
	return (false);
}
