/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:46:04 by revieira          #+#    #+#             */
/*   Updated: 2023/10/20 18:08:05 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	chosen;
	
	std::cout << CLEANWINDOW "Welcome to My Awesome PhoneBook!" << std::endl;
	std::cout << "Please choose an option:" << std::endl;
	while (1)
	{
		std::cout << "ADD | SEARCH | EXIT" << std::endl;
		if (!std::getline(std::cin, chosen))
			break ;
		if (chosen == "ADD")
			phoneBook.addContact();
		else if (chosen == "SEARCH")
			phoneBook.searchContact();
		else if (chosen == "EXIT")
		{
			std::cout << "Bye :)" << std::endl;
			break ;
		}
		else
			std::cout << RED "Invalid option please select one of the options below:" RESET << std::endl;
	}
	return (0);
}
