/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:04:57 by revieira          #+#    #+#             */
/*   Updated: 2023/08/08 15:50:22 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_amountOfContacts = 0;
}

PhoneBook::~PhoneBook() {}

int		PhoneBook::getAmountOfContacts()
{
	return this->_amountOfContacts;
}

void	PhoneBook::setAmountOfContacts(int amount)
{
	this->_amountOfContacts = amount;	
}

void	PhoneBook::addContact(int index, std::string info[6])
{
	int			currAmount;
	Contacts	newContact;

	currAmount = this->getAmountOfContacts();
	if (currAmount != 7)
		setAmountOfContacts(currAmount + 1);
	newContact.setContact(index, info);
	this->_contacts[index] = newContact;
}

void	PhoneBook::displayAllContacts()
{
	int	i;
	int	amount;

	i = 0;
	amount = this->getAmountOfContacts();
	if (amount == 0)
	{
		std::cout << "Phone book is empty" << std::endl;
		return ;
	}
	while (i < amount)
	{
		this->_contacts[i].displayContact();
		i++;
	}
}

void	PhoneBook::displayContact(int index)
{
}
