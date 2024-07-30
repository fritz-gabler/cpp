/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isValidContactNumber.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:42:50 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/11 14:25:37 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

static bool	isInRangeOfContactNumber(int input, int numberOfContacts);

bool	isValidContactNumber(int input, int numberOfContacts, Process process)
{
	if (isInRangeOfContactNumber(input, numberOfContacts) == true
		|| process.Status == Exit)
		return (true);
	return (false);

}

static bool	isInRangeOfContactNumber(int input, int numberOfContacts)
{
	if (input >= 0 && input < numberOfContacts)
		return (true);
	return (false);
}
