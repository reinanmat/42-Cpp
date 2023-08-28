/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:46:04 by revieira          #+#    #+#             */
/*   Updated: 2023/08/27 20:41:45 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	chosen;
	
	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	std::cout << "Please choose an option:" << std::endl;
	while (1)
	{
		std::cout << "1.ADD" << std::endl;
		std::cout << "2.SEARCH" << std::endl;
		std::cout << "3.EXIT" << std::endl;
		std::getline(std::cin, chosen);
		if (chosen.compare("ADD") == 0 || chosen.compare("1") == 0)
			phoneBook.addContact();
		else if (chosen.compare("SEARCH") == 0 || chosen.compare("2") == 0)
			phoneBook.searchContact();
		else if (chosen.compare("EXIT") == 0 || chosen.compare("3") == 0)
		{
			std::cout << "Bye :)" << std::endl;
			break ;
		}
		else
			std::cout << "Invalid option please select one of the options below:" << std::endl;
		std::cout << std::endl;
	}
	return (0);
}
