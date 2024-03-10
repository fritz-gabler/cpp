/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ValidePhoneNumber.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:10:07 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/10 11:42:54 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Header.hpp"

static bool	ValideLength(std::string PhoneNumber);
static bool	FirstDigitCheck(std::string PhoneNumber);
static bool	IsDigit(std::string PhoneNumber);

bool	ValidePhoneNumber(std::string PhoneNumber)
{
	if (ValideLength(PhoneNumber) == false)
		return (false);
	else if (FirstDigitCheck(PhoneNumber) == false)
		return (false);
	else if (IsDigit(PhoneNumber) == false)
		return (false);
	return (true);
}

static bool	ValideLength(std::string PhoneNumber)
{
	if (PhoneNumber.length() < 7 || PhoneNumber.length() > 15)
		return (false);
	return (true);
}

static bool	FirstDigitCheck(std::string PhoneNumber)
{
	if (PhoneNumber[0] == '+' || PhoneNumber[0] == '0')
		return (true);
	return (false);
}

static bool	IsDigit(std::string PhoneNumber)
{
	int	i;

	i = 1;
	while (PhoneNumber[i] != '\0')
	{
		if (std::isdigit(PhoneNumber[i]) == 0 && PhoneNumber[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}
