/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:39:02 by revieira          #+#    #+#             */
/*   Updated: 2024/01/30 17:49:59 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* CONSTRUCTORS AND DESTRUCTORS */
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	if (this != &obj)
		*this = obj;
}

BitcoinExchange::~BitcoinExchange() {}

/* OPERATORS OVERLOADING */
BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->_dataBase = other._dataBase;
	return (*this);
}

/* MEMBER FUNCTIONS */
static void	trim(std::string &str)
{
    str.erase(str.find_last_not_of(' ') + 1);
	if (str.find_first_not_of(' ') != std::string::npos)
		str.erase(0, str.find_first_not_of(' '));
}

static bool	validDate(const std::string &date)
{
	struct tm time;

	if (date.empty())
	{
		std::cerr << "Error: no date has been passed" << std::endl;
		return (false);
	}
	if (strptime(date.c_str(), "%Y-%m-%d", &time))
		return (true);
	std::cerr << "Error: bad input => " << date << std::endl;
	return (false);
}

static bool	isNumberOrFloatNumber(const std::string &str)
{
	std::string::const_iterator	it = str.begin();

	if (*it == '-' || *it == '+')
		it++;
	while (it != str.end() && std::isdigit(*it))
		it++;
	if (*it == '.' && it + 1 != str.end())
		it++;
	while (it != str.end() && std::isdigit(*it))
		it++;
	return (!str.empty() && it == str.end());
}

static float	convertToFloat(std::string str)
{
	float	num;
	std::stringstream	convert(str);
	convert >> num;
	return (num);
}

static bool	validValue(const std::string &value)
{
	if (value.empty())
	{
		std::cerr << "Error: no value was passed" << std::endl;
		return (false);
	}
	if (!isNumberOrFloatNumber(value))
	{
		std::cerr << "Error: not a number" << std::endl;
		return (false);
	}
	float num = convertToFloat(value);
	if (num < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (num > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange::initDataBase(std::string filename)
{
	float			value;
	std::string		line;
	std::string		key;
	std::ifstream	file(filename.c_str());

	if (!file.is_open())
	{
		std::cerr << "Error: Unable to open " << filename <<  " file" << std::endl;
		std::exit(1);
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string			tmpString;
		std::stringstream	inputString(line);
		std::getline(inputString, key, ',');
		std::getline(inputString, tmpString, ',');
		value = std::atof(tmpString.c_str());
		this->_dataBase.insert(std::make_pair(key, value));
	}
	file.close();
}

void	BitcoinExchange::seachInDataBase(std::string date, std::string value)
{
	float	finalValue;
	float	amount;

	if (!validDate(date) || !validValue(value))
		return ;
	amount = convertToFloat(value);
	std::map<std::string, float>::iterator	it;
	it = this->_dataBase.find(date);
	if (it != this->_dataBase.end())
		finalValue = amount * this->_dataBase.at(date);
	else
	{
		this->_dataBase[date] = 0;
		it = this->_dataBase.find(date);
		if (it == this->_dataBase.begin())
			finalValue = 0;
		else
		{
			it--;
			finalValue = amount * it->second;
		}
		this->_dataBase.erase(date);
	}
	std::cout << date << " => " << value << " = " << finalValue << std::endl;
}

void	BitcoinExchange::readInputFile(const std::string &filename)
{
	std::string		line;
	std::string		date;
	std::string		value;
	std::ifstream	file(filename.c_str());

	std::getline(file, line);
	line = "";
	while (std::getline(file, line))
	{
		std::stringstream	inputString(line);
		std::getline(inputString, date, '|');
		std::getline(inputString, value, '|');
		trim(date);
		trim(value);
		this->seachInDataBase(date, value);
	}
	file.close();
}

void	BitcoinExchange::printDataBase()
{
	std::map<std::string, float>::iterator	it;

	for (it = this->_dataBase.begin(); it != this->_dataBase.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
}
