/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 00:34:01 by nleoni            #+#    #+#             */
/*   Updated: 2025/04/14 19:26:04 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <vector>
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += _amount;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
}

void	Account::makeDeposit(int deposit) {
	int	p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit
			<< ";amount:" << _amount << ";nb_deposit:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	if (_amount >= withdrawal) {
		int	p_amount = _amount;
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal
				<< ";amount:" << _amount << ";nb_withdrawal:" << _nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
}

int	Account::checkAmount(void) const {
	return (_amount);
}

int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void) {
	time_t	timestamp = time(NULL);
	struct tm datetime = *localtime(&timestamp);
	char	timeDate[50];
	std::cout << "[";
	strftime(timeDate, 50, "%Y%m%d", &datetime);
	std::cout << timeDate;
	std::cout << "_";
	strftime(timeDate, 50, "%H%M%S", &datetime);
	std::cout << timeDate;
	std::cout << "] ";
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const {
		Account::_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";amount:" << _amount
			<< ";deposit:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
