/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:46:04 by revieira          #+#    #+#             */
/*   Updated: 2023/08/16 17:11:40 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

static int	validedNumber(std::string number)
{
	unsigned int	i;

	i = 0;
	while (i < number.size())
	{
		if (!isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

static std::string	getValue(std::string key)
{
	std::string	value;

	while (1)
	{
		std::cout << key << ": ";
		std::getline(std::cin, value);
		if (value.empty())
			std::cout << "Error: Empty field" << std::endl;
		else if (key.compare("phone book") == 0 && !validedNumber(value))
			std::cout << "Error: Not a valid phone number" << std::endl;
		else
			break;
	}
	return (value);
}

	
	phone.addContact(index, info);
	if (index == 8)
		index = 0;
}

void	seachContact(PhoneBook& phone)
{
	std::string	index;

	phone.displayAllContacts();	
	std::cout << "Choose a contact:" << std::endl;
	std::getline(std::cin, index);
	/* phone.displaySpecificContact(index); */
}

void	startPhone(void)
{
	PhoneBook	phone;
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
			addNewContact(phone);
		else if (chosen.compare("2") == 0)
			seachContact(phone);
		else if (chosen.compare("3") == 0)
		{
			std::cout << "Bye :)" << std::endl;
			break ;
		}
		else
			std::cout << "Invalid option please select one of the options below:" << std::endl;
	}
}

int	main(void)
{
	startPhone();
	return (0);
}
