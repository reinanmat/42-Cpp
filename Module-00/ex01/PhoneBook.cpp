/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:04:57 by revieira          #+#    #+#             */
/*   Updated: 2023/07/28 18:47:34 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::addContact()
{
	static int	index = 0;
	Contacts	newContact;

	if (index == 8)
		index = 0;
	this->contacts[index] = newContact.createContact(index);
}

/* void	PhoneBook::searchContact(int index) {} */
