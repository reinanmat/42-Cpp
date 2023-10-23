/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:09:56 by revieira          #+#    #+#             */
/*   Updated: 2023/10/23 15:35:02 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Contacts::Contacts() {}

Contacts::Contacts(const Contacts &obj)
{
	if (this != &obj)
		*this = obj;
}

Contacts::~Contacts() {}

/* OPERATORS OVERLOADING */
Contacts	&Contacts::operator=(const Contacts &other)
{
	if (this != &other)
	{
		this->_index = other._index;
		this->_nickname = other._nickname;
		this->_firstName = other._firstName;
		this->_lastName = other._lastName;
		this->_phoneNumber = other._phoneNumber;
		this->_darkestSecret = other._darkestSecret;
	}
	return *this;	
}

/* GETTERS AND SETTERS */
int			Contacts::getIndex() const { return this->_index; }
std::string	Contacts::getPhoneNumber() const { return this->_phoneNumber; }
std::string	Contacts::getFirstName() const { return this->_firstName; }
std::string	Contacts::getLastName() const { return this->_lastName; }
std::string	Contacts::getNickname() const { return this->_nickname; }
std::string	Contacts::getDarkestSecret() { return this->_darkestSecret; }
void		Contacts::setIndex(int index){ this->_index = index + 1; }
void		Contacts::setPhoneNumber(std::string phoneNumber) { this->_phoneNumber = phoneNumber; }
void		Contacts::setFirstName(std::string firstName) { this->_firstName = firstName; }
void		Contacts::setLastName(std::string lastName) { this->_lastName = lastName; }
void		Contacts::setNickname(std::string nickname) { this->_nickname = nickname; }
void		Contacts::setDarkestSecret(std::string darkestSecret) { this->_darkestSecret = darkestSecret; }

/* AUX FUNCTIONS */
static std::string	truncateString(std::string str)
{
	std::string	truncated;

	if (str.length() > 10)
		truncated = str.substr(0, 9) + '.';
	else
		truncated = str;
	return (truncated);
}

/* MEMBER FUNCTIONS */
void	Contacts::displaySimplifiedContact() const
{
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << this->_index;
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << truncateString(this->_firstName);
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << truncateString(this->_lastName);
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << truncateString(this->_nickname);
	std::cout << "|" << std::endl;
}

void	Contacts::displayFullContact() const
{
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}
