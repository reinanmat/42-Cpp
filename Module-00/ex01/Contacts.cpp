/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:09:56 by revieira          #+#    #+#             */
/*   Updated: 2023/08/16 14:46:17 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

Contacts::Contacts() {}

Contacts::~Contacts() {}

void	Contacts::setContact(int index, std::string info[5])
{
	this->_index = index;
	this->_nickname = info[0];
	this->_firstName = info[1];
	this->_lastName = info[2];
	this->_phoneNumber = info[3];
	this->_darkestSecret = info[4];
}

int	Contacts::getIndex() {
	return this->_index;
}

std::string	Contacts::getPhoneNumber() {
	return this->_phoneNumber;
}

std::string	Contacts::getFirstName() {
	return this->_firstName;
}

std::string	Contacts::getLastName() {
	return this->_lastName;
}

std::string	Contacts::getNickname() {
	return this->_nickname;
}

std::string	Contacts::getDarkestSecret() {
	return this->_darkestSecret;
}

std::string	truncate(std::string s)
{
	std::string	truncatedStr;

	if (s.length() > 10)
		truncatedStr = s.substr(0, 9) + '.';
	else
		truncatedStr = s;
	return (truncatedStr);
}

void	Contacts::displaySimplifiedContact()
{
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << this->getIndex();
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << truncate(this->getFirstName());
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << truncate(this->getLastName());
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << truncate(this->getNickname());
	std::cout << "|" << std::endl;
}

void	Contacts::displayFullContact()
{
	std::cout << "First Name: " << getFirstName() << std::endl;
	std::cout << "Last Name: " << getLastName() << std::endl;
	std::cout << "Nickname: " << getNickname() << std::endl;
	std::cout << "Phone Number: " << getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << getDarkestSecret() << std::endl;
}

Contacts& Contacts::operator=(Contacts other)
{
	this->_index = other._index;
	this->_nickname = other._nickname;
	this->_firstName = other._firstName;
	this->_lastName = other._lastName;
	this->_phoneNumber = other._phoneNumber;
	this->_darkestSecret = other._darkestSecret;
	return *this;	
}

