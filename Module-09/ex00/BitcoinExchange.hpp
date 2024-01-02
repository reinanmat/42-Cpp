/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:57:39 by revieira          #+#    #+#             */
/*   Updated: 2024/01/02 19:58:48 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>

#define DATAFILE "./data.csv"

typedef std::map<std::string, float> t_map;

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const std::iostream &data);
		BitcoinExchange(const BitcoinExchange &obj);
		~BitcoinExchange();
		BitcoinExchange	&operator=(const BitcoinExchange &other);
		void	initDataBase();
		void	printDataBase();
		

	private:
		t_map	_dataBase;
};
