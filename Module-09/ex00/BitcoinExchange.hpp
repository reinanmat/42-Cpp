/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:57:39 by revieira          #+#    #+#             */
/*   Updated: 2024/01/03 16:33:45 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <map>

#define DATAFILE "./data.csv"

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const std::iostream &data);
		BitcoinExchange(const BitcoinExchange &obj);
		~BitcoinExchange();
		BitcoinExchange	&operator=(const BitcoinExchange &other);
		void	initDataBase();
		void	readInputFile(const std::string &filename);
		void	seachInDataBase(std::string date, std::string value);
		void	printDataBase();

	private:
		std::map<std::string, float>	_dataBase;
};
