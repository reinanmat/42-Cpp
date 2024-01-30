/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:11:24 by revieira          #+#    #+#             */
/*   Updated: 2024/01/30 17:57:11 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool	validArgs(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (false);
	}
	if (argc != 2)
	{
		std::cerr << "Error: invalid number of arguments" << std::endl;
		std::cerr << "Usage: ./btc <FILE>" << std::endl;
		return (false);
	}
	std::ifstream	file(argv[1]);
	if (!file.is_open())
	{
		std::cerr << "Error: failed to open a file" << std::endl;
		return (false);
	}
	file.close();
	return (true);
}

int	main(int argc, char **argv)
{
	if (!validArgs(argc, argv))
		return (1);
	try {
		BitcoinExchange data;
		data.initDataBase(DATAFILE);
		data.readInputFile(argv[1]);
	} catch (...) {
		std::cerr << "Error: unexpected error" << std::endl;
	}
	return (0);
}
