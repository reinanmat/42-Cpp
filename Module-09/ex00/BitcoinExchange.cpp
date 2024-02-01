/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:39:02 by revieira          #+#    #+#             */
/*   Updated: 2024/02/01 15:17:17 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iomanip>

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

static bool	isLeapYear(const int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

static int	numberOfDaysThisMonth(const int year, const int month)
{
	if (month == 2)
		return (isLeapYear(year) ? 29 : 28);
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		return (30);
	else
		return (31);
}

static bool emptyDateOrValue(const std::string &date, const std::string &value)
{
	if (date.empty())
	{
		std::cerr << "Error: no date was passed" << std::endl;
		return (true);
	}
	else if (value.empty())
	{
		std::cerr << "Error: no value was passed" << std::endl;
		return (true);
	}
	return (false);
}

static bool	validDate(const std::string &date)
{
	if (date.length() > 10)
		return (false);
	int year = std::atoi(date.c_str());
	int	month = std::atoi(date.c_str() + 5);
	int	day = std::atoi(date.c_str() + 8);
	if (year < 1 || year > 9999)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > numberOfDaysThisMonth(year, month))
		return (false);
	return (true);
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

static float	convertToFloat(const std::string &str)
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

static bool	validHeaderFile(std::string &headerFile, int type)
{
	std::string			date;
	std::string			value;
	std::stringstream	inputString(headerFile);
	if (type == DATA)
	{
		std::getline(inputString, date, ',');
		std::getline(inputString, value, '\0');
		trim(date);
		trim(value);
		if (date != "date" || value != "exchange_rate")
			return (false);
	}
	else if (type == INPUT)
	{
		std::getline(inputString, date, '|');
		std::getline(inputString, value, '\0');
		trim(date);
		trim(value);
		if (date != "date" || value != "value")
			return (false);
	}
	return (true);
}

void	BitcoinExchange::initDataBase(std::string filename)
{
	float			value;
	std::string		tmpValue;
	std::string		line;
	std::string		date;
	std::ifstream	file(filename.c_str());

	if (!file.is_open())
	{
		std::string errorMsg = "Error: " + filename + " file was not found";
		throw std::runtime_error(errorMsg);
	}
	std::getline(file, line);
	if (!validHeaderFile(line, DATA))
	{
		file.close();
		throw std::runtime_error("Error: data file or header in invalid format, use \"date,exchange_rate\"");
	}
	while (std::getline(file, line))
	{
		if (!line.empty())
		{
			std::stringstream	inputString(line);
			std::getline(inputString, date, ',');
			std::getline(inputString, tmpValue, ',');
			if (date.empty() || tmpValue.empty())
				continue ;
			else if (!validDate(date))
				continue ;
			else if (!isNumberOrFloatNumber(tmpValue))
				continue ;
			value = std::atof(tmpValue.c_str());
			this->_dataBase.insert(std::make_pair(date, value));
		}
	}
	file.close();
}

void	BitcoinExchange::seachInDataBase(std::string date, std::string value)
{
	float	finalValue;
	float	amount;

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
	if (!validHeaderFile(line, INPUT))
	{
		file.close();
		throw std::runtime_error("Error: input file or header in invalid format, use \"date | value\"");
	}
	while (std::getline(file, line))
	{
		if (!line.empty())
		{
			std::stringstream	inputString(line);
			std::getline(inputString, date, '|');
			std::getline(inputString, value, '\0');
			trim(date);
			trim(value);
			if (emptyDateOrValue(date, value))
				continue ;
			else if (!validDate(date))
			{
				std::cerr << "Error: bad input => " << date << std::endl;
				continue ;
			}
			else if (!validValue(value))
				continue ;
			this->seachInDataBase(date, value);
		}
	}
	file.close();
}

void	BitcoinExchange::printDataBase()
{
	std::map<std::string, float>::iterator	it;

	for (it = this->_dataBase.begin(); it != this->_dataBase.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
}
