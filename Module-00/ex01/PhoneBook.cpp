/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:04:57 by revieira          #+#    #+#             */
/*   Updated: 2023/10/02 17:42:58 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_amountOfContacts = 0;
}

PhoneBook::~PhoneBook() {}

Contacts	PhoneBook::getContact(int index)
{
	return this->_contacts[index];
}

int	PhoneBook::getAmountOfContacts()
{
	return this->_amountOfContacts;
}

void	PhoneBook::setAmountOfContacts(int amount)
{
	this->_amountOfContacts = amount;	
}

static int	checkEmptyField(std::string	str)
{
	size_t	i;

	if (str.empty())
		return (1);
	i = 0;
	while (isspace(str[i]))
		i++;
	if (i == str.size())
		return (1);
	return (0);
}

static int	checkNumber(std::string number)
{
	size_t	i;

	i = 0;
	while (i < number.size())
	{
		if (!isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	checkUnicodeChar(std::string str)
{
	size_t	i;

	i = 0;
	while (i < str.size())
	{
		if (!(str[i] & 0b10000000))
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
		if (checkEmptyField(value))
			std::cout << "Error: Empty field" << std::endl;
		else if (key.compare("phone book") == 0 && !checkNumber(value))
			std::cout << "Error: Not a valid phone number" << std::endl;
		else if (checkUnicodeChar(value))
			std::cout << "Error: Unsupported unicode characteres" << std::endl;
		else
			break;
	}
	return (value);
}

void	PhoneBook::addContact()
{
	static int	index = 0;
	int			currAmount;
	Contacts	newContact;

	currAmount = this->getAmountOfContacts();
	if (currAmount != 8)
		setAmountOfContacts(currAmount + 1);
	newContact.setIndex(index);
	newContact.setFirstName(getValue("first name"));
	newContact.setLastName(getValue("last name"));
	newContact.setNickname(getValue("nickname"));
	newContact.setPhoneNumber(getValue("phone book"));
	newContact.setDarkestSecret(getValue("darkest secret"));
	this->_contacts[index] = newContact;
	if (++index == 8)
		index = 0;
}

void	PhoneBook::searchContact()
{
	std::string strIndex;
	int			index;
	int			amount;

	amount = this->getAmountOfContacts();
	if (amount == 0)
	{
		std::cout << "Phone book is empty" << std::endl;
		return ;
	}
	this->displayAllContacts();
	while (1)
	{
		std::cout << "Choose a contact:" << std::endl;
		std::getline(std::cin, strIndex);
		if (!checkNumber(strIndex))
			std::cout << "Not a number" << std::endl;
		index = std::atoi(strIndex.c_str()) - 1;
		if (index < 0 || index > amount - 1)
			std::cout << "Error: index out of range" << std::endl;
		else
			break ;
	}
	this->displayContact(index);
}

void	PhoneBook::displayAllContacts()
{
	int			i;
	int			amount;
	Contacts	contact;

	i = 0;
	amount = this->getAmountOfContacts();
	std::cout << "/===========================================\\" << std::endl;
	std::cout << "|  INDEX   |FIRST NAME|LAST  NAME| NICKNAME |" << std::endl;
	while (i < amount)
	{
		contact = this->getContact(i);
		contact.displaySimplifiedContact();
		i++;
	}
	std::cout << "\\===========================================/" << std::endl;
}

void	PhoneBook::displayContact(int index)
{
	Contacts	contact;

	contact = this->getContact(index);
	contact.displayFullContact();
}
