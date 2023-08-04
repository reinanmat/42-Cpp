/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:09:56 by revieira          #+#    #+#             */
/*   Updated: 2023/08/04 16:06:13 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include <iomanip>

Contacts::Contacts() {}

Contacts::~Contacts() {}

void	Contacts::new_contact(int index)
{	
	this->index = index + 1;
	this->first_name = get_info("First Name: ");
	this->last_name = get_info("Last Name: ");
	this->nickname = get_info("Nickname: ");
	this->phone_number = get_number();
	this->darkest_secret = get_info("Darkest secret: ");
}

void	Contacts::display_contact()
{
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << this->index;
	/* std::cout << this->first_name; */
	/* std::cout << this->last_name; */
	/* std::cout << this->nickname; */
	std::cout << "|" << std::endl;
}

bool	isnumber(std::string s)
{
	for (int i = 0; s[i]; i++)
		if (std::isalnum(s[i]) == 0)
			return (false);
	return (true);
}

int			Contacts::get_number()
{
	int			phone_number;
	std::string	input;

	std::cout << "Phone number: ";
	while (1)
	{
		std::getline(std::cin, input);	
		if (isnumber(input))
			break ;
		
	}
	phone_number = 1;
	return (phone_number);
}

std::string	Contacts::get_info(std::string wanted_info)
{
	std::string	 info;

	std::cout << wanted_info;
	std::getline(std::cin, info);

	return (info);
}

Contacts& Contacts::operator=(Contacts other)
{
	this->index = other.index;
	this->nickname = other.nickname;
	this->first_name = other.first_name;
	this->last_name = other.last_name;
	this->phone_number = other.phone_number;
	this->darkest_secret = other.darkest_secret;
	return *this;	
}

