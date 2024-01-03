/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:11:24 by revieira          #+#    #+#             */
/*   Updated: 2024/01/03 16:48:51 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool	validArgs(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		std::cerr << "Usage: ./btc <FILE>" << std::endl;
		return (false);
	}
	std::ifstream	file(argv[1]);
	if (!file.is_open())
	{
		std::cerr << "Error: No such file or directory" << std::endl;
		return (false);
	}
	file.close();
	return (true);
}

int	main(int argc, char **argv)
{
	if (!validArgs(argc, argv))
		return (1);
	BitcoinExchange data;
	data.initDataBase();
	data.readInputFile(argv[1]);
	return (0);
}
