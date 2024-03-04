/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:22:12 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/04 08:58:12 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int		Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return (_totalAmount);
}


int		Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	std::cout
		<< "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawls" << _totalNbWithdrawals << ";"
		<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t		currentTime;
	struct tm	*localTime;
	char		displayTime[18];

	std::time(&currentTime);
	localTime = localtime(&currentTime);
	strftime(displayTime, 18, "[%Y%m%d_%H%M%S]", localTime);
	std::cout << displayTime << std::endl;

}
