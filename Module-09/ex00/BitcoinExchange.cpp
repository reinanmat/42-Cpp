/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:39:02 by revieira          #+#    #+#             */
/*   Updated: 2024/01/02 19:58:30 by revieira         ###   ########.fr       */
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
void	BitcoinExchange::initDataBase()
{
	std::string		line;
	std::ifstream	file(DATAFILE);
	std::string		key;
	float			value;

	std::getline(file, line);
	line = "";
	while (std::getline(file, line))
	{
		std::string			tmpString;
		std::stringstream	inputString(line);
		std::getline(inputString, key, ',');
		std::getline(inputString, tmpString, ',');
		value = std::atof(tmpString.c_str());
		this->_dataBase.insert(std::make_pair(key, value));
		line = "";
	}
}

void	BitcoinExchange::printDataBase()
{
	t_map::iterator	it;

	for (it = this->_dataBase.begin(); it != this->_dataBase.end(); it++)
		std::cout << it->first << " : " << it->second << std::endl;
}
