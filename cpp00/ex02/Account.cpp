/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:22:12 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/03 12:02:09 by fgabler          ###   ########.fr       */
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
	return (_nbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return (_nbWithdrawals);
}

Account::Account(int initial_deposit)
{
	
}

void	Account::displayAccountsInfos(void)
{
	std::cout
		<< "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawls" << _nbWithdrawals << ";"
		<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	
}
