/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:09:56 by revieira          #+#    #+#             */
/*   Updated: 2023/09/27 17:36:43 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

Contacts::Contacts() {}

Contacts::~Contacts() {}

void	Contacts::setIndex(int index)
{
	this->_index = index + 1;
}

void	Contacts::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}
void	Contacts::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

void	Contacts::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

void	Contacts::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}

void	Contacts::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

int	Contacts::getIndex()
{
	return this->_index;
}

std::string	Contacts::getPhoneNumber()
{
	return this->_phoneNumber;
}

std::string	Contacts::getFirstName()
{
	return this->_firstName;
}

std::string	Contacts::getLastName()
{
	return this->_lastName;
}

std::string	Contacts::getNickname()
{
	return this->_nickname;
}

std::string	Contacts::getDarkestSecret()
{
	return this->_darkestSecret;
}

static std::string	truncate_str(std::string str)
{
	std::string	truncated;

	if (str.length() > 10)
		truncated = str.substr(0, 9) + '.';
	else
		truncated = str;
	return (truncated);
}

void	Contacts::displaySimplifiedContact()
{
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << this->getIndex();
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << truncate_str(this->getFirstName());
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << truncate_str(this->getLastName());
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << truncate_str(this->getNickname());
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
