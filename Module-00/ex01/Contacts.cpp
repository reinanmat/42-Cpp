/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:09:56 by revieira          #+#    #+#             */
/*   Updated: 2023/08/08 15:42:12 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include <iomanip>

Contacts::Contacts() {}

Contacts::~Contacts() {}

void	Contacts::setContact(int index, std::string *info)
{
	this->_index = index;
	this->_nickname = info[1];
	this->_firstName = info[2];
	this->_lastName = info[3];
	this->_phoneNumber = stoi(info[4]);
	this->_darkestSecret = info[5];
}

int	Contacts::getIndex() {
	return this->_index;
}

int	Contacts::getPhoneNumber() {
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

void	Contacts::displayContact()
{
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << this->getIndex();
	/* std::cout << this->getFirstName(); */
	/* std::cout << this->getLastName(); */
	/* std::cout << this->getNickname(); */
	std::cout << "|" << std::endl;
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

