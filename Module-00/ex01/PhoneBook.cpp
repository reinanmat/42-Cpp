/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:04:57 by revieira          #+#    #+#             */
/*   Updated: 2023/10/20 18:18:00 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
PhoneBook::PhoneBook()
{
	this->_amountOfContacts = 0;
}

PhoneBook::PhoneBook(const PhoneBook &obj)
{
	if (this != &obj)
		*this = obj;
}

PhoneBook::~PhoneBook() {}

/* OPERATOR OVERLOADING */
PhoneBook	&PhoneBook::operator=(const PhoneBook &cpy)
{
	if (this != &cpy)
	{
		this->_amountOfContacts = cpy._amountOfContacts;
		for (int i = 0; i < cpy._amountOfContacts; i++)
			this->_contacts[i] = cpy._contacts[i];
	}
	return (*this);
}

/* GETTERS AND SETTERS */
Contacts	PhoneBook::getContact(int index) const
{
	return this->_contacts[index];
}

int	PhoneBook::getAmountOfContacts() const
{
	return this->_amountOfContacts;
}

void	PhoneBook::setAmountOfContacts(int amount)
{
	this->_amountOfContacts = amount;	
}

/* MEMBER FUNCTIONS */
void	PhoneBook::addContact()
{
	static int	index = 0;
	Contacts	newContact;

	if (this->_amountOfContacts != 8)
		this->_amountOfContacts += 1;
	newContact.setIndex(index);
	newContact.setFirstName(getInput("first name"));
	newContact.setLastName(getInput("last name"));
	newContact.setNickname(getInput("nickname"));
	newContact.setPhoneNumber(getInput("phone book"));
	newContact.setDarkestSecret(getInput("darkest secret"));
	this->_contacts[index] = newContact;
	if (++index == 8)
		index = 0;
}

void	PhoneBook::searchContact() const
{
	std::string strIndex;
	int			index;

	if (this->_amountOfContacts == 0)
	{
		std::cout << YEL "Phone book is empty!" RESET << std::endl;
		return ;
	}
	this->displayAllContacts();
	while (1)
	{
		std::cout << "Choose a contact:" << std::endl;
		if (!std::getline(std::cin, strIndex))
			exit(1);
		if (!checkNumber(strIndex))
		{
			std::cout << RED "Error: Invalid number" RESET << std::endl;
			continue ;
		}
		index = std::atoi(strIndex.c_str()) - 1;
		if (index < 0 || index > this->_amountOfContacts - 1)
			std::cout << RED "Error: Index out of range" RESET << std::endl;
		else
			break ;
	}
	this->displayContact(index);
}

void	PhoneBook::displayAllContacts() const
{
	int			i;
	Contacts	contact;

	i = 0;
	std::cout << "/===========================================\\" << std::endl;
	std::cout << "|  INDEX   |FIRST NAME|LAST  NAME| NICKNAME |" << std::endl;
	while (i < this->_amountOfContacts)
	{
		contact = this->getContact(i);
		contact.displaySimplifiedContact();
		i++;
	}
	std::cout << "\\===========================================/" << std::endl;
}

void	PhoneBook::displayContact(int index) const
{
	Contacts	contact;

	contact = this->getContact(index);
	contact.displayFullContact();
}
