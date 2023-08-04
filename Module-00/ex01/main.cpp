/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:46:04 by revieira          #+#    #+#             */
/*   Updated: 2023/08/04 16:07:16 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	startPhone(void)
{
	std::string	chosen;
	PhoneBook	phone;
	
	std::cout << "Welcome to my PhoneBook" << std::endl;
	while (1)
	{
		std::cout << "1.ADD" << std::endl;
		std::cout << "2.SEARCH" << std::endl;
		std::cout << "3.EXIT" << std::endl;
		std::getline(std::cin, chosen);
		if (chosen.compare("ADD") || chosen.compare("1") == 0)
			phone.add_contact();
		else if (chosen.compare("2") == 0)
			phone.search_contact();
		else if (chosen.compare("3") == 0)
			break ;
		else
			std::cout << "Invalid option please select one of the options below" << std::endl;
	}
}

int	main(void)
{
	startPhone();
	return (0);
}
