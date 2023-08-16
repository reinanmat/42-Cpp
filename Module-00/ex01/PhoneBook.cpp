/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:04:57 by revieira          #+#    #+#             */
/*   Updated: 2023/08/16 17:14:46 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_amountOfContacts = 0;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::setAmountOfContacts(int amount)
{
	this->_amountOfContacts = amount;	
}

Contacts	PhoneBook::getContact(int index)
{
	return this->_contacts[index];
}

int	PhoneBook::getAmountOfContacts()
{
	return this->_amountOfContacts;
}

void	PhoneBook::addContact(int index, std::string info[5])
{
	int			currAmount;
	Contacts	newContact;

	currAmount = this->getAmountOfContacts();
	if (currAmount != 8)
		setAmountOfContacts(currAmount + 1);
	newContact.setContact(index, info);
	this->_contacts[index] = newContact;
}

int	PhoneBook::displayContacts()
{
	int			i;
	int			amount;
	Contacts	contact;

	i = 0;
	amount = this->getAmountOfContacts();
	if (amount == 0)
	{
		std::cout << "Phone book is empty" << std::endl;
		return (-1);
	}
	std::cout << "| index | first name | last name | nickname |" << std::endl;
	while (i < amount)
	{
		contact = this->getContact(i);
		contact.displaySimplifiedContact();
		i++;
	}
	return (0);
}

int	PhoneBook::displayContacts(int index)
{
	int			amount;
	Contacts	contact;

	amount = this->getAmountOfContacts();
	index = index - 1;
	if (index < 0 || index > amount - 1)
	{
		std::cout << "Error: index out of range" << std::endl;
		return (-1);
	}
	contact = this->getContact(index);
	contact.displayFullContact();
	return (0);
}
