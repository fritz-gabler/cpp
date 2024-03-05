/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:22:12 by fgabler           #+#    #+#             */
/*   Updated: 2024/03/05 16:16:44 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <filesystem>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

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
	_displayTimestamp();
	std::cout
		<< "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawls" << _totalNbWithdrawals
		<< std::endl;
}


Account::Account(int initial_deposit)
{
	this->_accountIndex = getNbAccounts();
	this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created"
		<< std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed"
		<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_amount += deposit;
	this->_totalNbDeposits++;
	_totalAmount += deposit; this->_nbDeposits++; std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << (this->_amount - deposit) << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_deposits:" << this->_nbDeposits
		<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	bool		withdrawalPossible;

	_displayTimestamp();
	withdrawalPossible = false;
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";";

	if ((_nbWithdrawals - withdrawal) >= 0)
	{
		this->_nbWithdrawals += withdrawal;
		_totalNbWithdrawals++;
		withdrawalPossible = true;
		std::cout
			<< "deposit:" << this->_nbDeposits << ";"
			<< "withdrawal:" << withdrawal
			<< "amount:" << this->_amount << ";"
			<< "nb_withdrawal:" << this->_totalNbWithdrawals
			<< std::endl;
	}
	else
	{
		std::cout
			<< "withdrawals:refused"
			<< std::endl;
	}
	return (withdrawalPossible);
	//return ((_nbWithdrawals - withdrawal) >= 0 ? true:false);
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawls:" << _totalNbWithdrawals
		<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t		currentTime;
	struct tm	*localTime;
	char		displayTime[19];

	std::time(&currentTime);
	localTime = localtime(&currentTime);
	strftime(displayTime, 19, "[%Y%m%d_%H%M%S] ", localTime);
	std::cout << displayTime;
}
