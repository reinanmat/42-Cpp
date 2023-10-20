/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:15:37 by revieira          #+#    #+#             */
/*   Updated: 2023/10/20 14:25:31 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

static int index = 0;
static int nbAccounts = 0;
static int totalAmount = 0;
static int totalDeposits = 0;
static int totalWithdrawals = 0;

/* AUX FUNCTIONS */
static	std::string	getCurrentDateTime(void)
{
	time_t		now = time(0);
	char		buffer[80];
	struct tm	timeInfo;

	timeInfo = *localtime(&now);
	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", &timeInfo);
	return (buffer);
}

static	std::string	to_string(int value)
{
	std::stringstream ss;

	ss << value;
	return (ss.str());
}

static	void	writeInLogFile(std::string logMsg)
{
	std::string now;
	std::string filename;

	now = getCurrentDateTime();
	filename = now + ".log";
	std::ofstream	logFile(filename.c_str(), std::ofstream::out | std::ofstream::app);
	logFile << "[" + now + "] " << logMsg << std::endl;
	logFile.close();
}

/* CONSTRUCTORS AND DESTRUCTOR */
Account::Account() {}

Account::Account(const Account &obj)
{
	if (this != &obj)
		*this = obj;
}

Account::Account(int amount)
{
	std::string logMsg;

	this->_index = index;
	this->_amount = amount;
	logMsg = "index:" + to_string(this->_index) + ";";
	logMsg += "amount:" + to_string(this->_amount) + ";";
	logMsg += "created";
	writeInLogFile(logMsg);
	index++;
	nbAccounts++;
	totalAmount += amount;
}

Account::~Account()
{
	std::string	logMsg;

	logMsg = "index:" + to_string(this->_index) + ";";
	logMsg += "amount:" + to_string(this->_amount) + ";";
	logMsg += "closed";
	writeInLogFile(logMsg);
}

/* GETTERS AND SETTERS */
int		Account::getIndex(void) { return this->_index; }
int		Account::getAmount(void) { return this->_amount; }
int		Account::getDeposits(void) { return this->_deposits; }
int		Account::getWithdrawals(void) { return this->_withdrawals; }
void	Account::setIndex(int index) { this->_index = index; };
void	Account::setAmount(int amount) { this->_amount = amount; }
void	Account::setDeposits(int deposit) { this->_deposits = deposit ;}
void	Account::setWithdrawals(int withdrawals) { this->_withdrawals = withdrawals; }

/* OPERATORS OVERLOADING */
Account	&Account::operator=(const Account &other)
{
	if (this != &other)
	{
		this->_index = other._index;
		this->_amount = other._amount;
		this->_deposits = other._deposits;
		this->_withdrawals = other._withdrawals;
	}
	return (*this);
}

/* MEMBER FUNCTIONS */
void	Account::displayAccountsInfos(void)
{
	std::string	logMsg;

	logMsg = "accounts:" + to_string(nbAccounts) + ";";
	logMsg += "total:" + to_string(totalAmount) + ";";
	logMsg += "deposits:" + to_string(totalDeposits) + ";";
	logMsg += "withdrawals:" + to_string(totalWithdrawals);
	writeInLogFile(logMsg);
}

void	Account::displayStatus(void)
{
	std::string	logMsg;

	logMsg = "index:" + to_string(this->_index) + ";";
	logMsg += "amount:" + to_string(this->_amount) + ";";
	logMsg += "deposits:" + to_string(this->_deposits) + ";";
	logMsg += "withdrawals:" + to_string(this->_withdrawals);
	writeInLogFile(logMsg);
}

void	Account::makeDeposit(int deposit)
{
	std::string logMsg;

	logMsg = "index:" + to_string(this->_index) + ";";
	logMsg += "p_amount:" + to_string(this->_amount) + ";";
	logMsg += "deposit:" + to_string(deposit) + ";";
	this->_amount += deposit;
	this->_deposits += 1;
	logMsg += "amount:" + to_string(this->_amount) + ";";
	logMsg += "nb_deposits:" + to_string(this->_deposits);
	writeInLogFile(logMsg);
	totalDeposits++;
	totalAmount += deposit;
}

void	Account::makeWithdrawal(int withdrawal)
{
	std::string	logMsg;

	logMsg = "index:" + to_string(this->_index) + ";";
	logMsg += "p_amount:" + to_string(this->_amount) + ";";
	if (this->_amount - withdrawal < 0)
	{
		logMsg = logMsg + "withdrawal:refused";
		writeInLogFile(logMsg);
		return ;
	}
	this->_amount -= withdrawal;
	this->_withdrawals += 1;
	logMsg += "withdrawal:" + to_string(withdrawal) + ";";
	logMsg += "amount:" + to_string(this->_amount) + ";";
	logMsg += "nb_withdrawals:" + to_string(this->_withdrawals);
	writeInLogFile(logMsg);
	totalWithdrawals++;
	totalAmount -= withdrawal;
}
