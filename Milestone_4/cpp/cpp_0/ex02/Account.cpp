/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:50:59 by yoherfan          #+#    #+#             */
/*   Updated: 2025/09/17 13:54:18 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts()
{
    return (_nbAccounts);
}

int Account::getTotalAmount()
{
    return (_totalAmount);
}

int	Account::getNbDeposits()
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
    return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp()
{
	std::time_t current_time = std::time(NULL);
    std::tm* 	local_time = std::localtime(&current_time);
	std::cout << "["
			  << (local_time->tm_year + 1900)
			  << (local_time->tm_mon + 1)
			  << local_time->tm_mday
			  << "_"
			  << local_time->tm_hour
			  << local_time->tm_min
			  << local_time->tm_sec
			  << "] ";
}

void    Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:"
			  << Account::getNbAccounts()
			  << ";total:"
			  << Account::getTotalAmount() 
			  << ";deposits:"
			  << Account::getNbDeposits()
			  << ";withdrawals:"
			  << Account::getNbWithdrawals()
			  << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:"
			  << _accountIndex
			  << ";amount:"
			  << this->_amount
			  << ";deposits:"
			  << this->_nbDeposits
			  << ";withdrawals:"
			  << this->_nbWithdrawals
			  << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:"
			  << _accountIndex
			  << ";p_amount:"
			  << this->_amount
			  << ";deposit:"
			  << deposit;
	this->_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << ";amount:"
			  << this->_amount
			  << ";nb_deposits:"
			  << _nbDeposits
			  << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:"
			  << _accountIndex
			  << ";p_amount:"
			  << this->_amount
			  << ";withdrawal:";
	if (this->_amount - withdrawal >= 0)
	{
		std::cout	  << withdrawal;
		this->_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << ";amount:"
			 	  << this->_amount
			  	  << ";nb_withdrawals:"
			  	  << _nbWithdrawals
			  	  << std::endl;			
	}
	else
	{
		std::cout << "refused"
				  << std::endl;
	}
	return (0);
}

Account::Account(int initial_deposit )
{
	_displayTimestamp();
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += _amount;
	std::cout << "index:"
			  << _accountIndex
			  << ";amount:"
			  << _amount
			  << ";created"
			  << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:"
			  << _accountIndex
			  << ";amount:"
			  << _amount
			  << ";closed"
			  << std::endl;
}

// int		main( void )
// {


// 	    // Ottieni l'ora corrente in formato time_t
//     std::time_t current_time = std::time(NULL);

//     // Converte il time_t in una struttura tm per l'orario locale
//     std::tm* local_time = std::localtime(&current_time);

//     // Stampa la data e ora locale in formato leggibile
//     std::cout << "Data e ora locale: "
//               << (local_time->tm_mday) << "/"
//               << (local_time->tm_mon + 1) << "/"
//               << (local_time->tm_year + 1900) << " "
//               << (local_time->tm_hour) << ":"
//               << (local_time->tm_min) << ":"
//               << (local_time->tm_sec)
//               << std::endl;

//     return 0;
// }