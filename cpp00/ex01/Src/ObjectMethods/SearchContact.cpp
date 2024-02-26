/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SearchContact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:06:14 by fgabler           #+#    #+#             */
/*   Updated: 2024/02/25 17:37:27 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::SearchContact(int *LinesPrinted)
{
	int		i;

	i = 0;
	while (i < NumberOfContacts)
	{
		Contact[i].DisplayContact(i);
		*LinesPrinted += 4;
		i++;
	}
}

bool	PhoneBook::ContactExist()
{
	if (NumberOfContacts > 0)
		return (true);
	return (false);
}
