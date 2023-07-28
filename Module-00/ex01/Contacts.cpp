/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:09:56 by revieira          #+#    #+#             */
/*   Updated: 2023/07/28 18:40:13 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

Contacts::Contacts() {}

Contacts::~Contacts() {}

void	Contacts::createContact(int index)
{	
	this->index = index;
	std::cout << "First Name: ";
	std::cin >> this->firstName;
	std::cout << std::endl;
	std::cout << "Last Name: ";
	std::cin >> this->lastName;	
	std::cout << std::endl;
	std::cout << "Nickname: ";
	std::cin >> this->nickname;	
	std::cout << std::endl;
	std::cout << "Phone Number: ";
	std::cin >> this->phoneNumber;	
	std::cout << std::endl;
	std::cout << "Darkest secret: ";
	std::cin >> this->darkestSecret;	
	std::cout << std::endl;
}
