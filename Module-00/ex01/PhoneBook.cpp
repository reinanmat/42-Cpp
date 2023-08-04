/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:04:57 by revieira          #+#    #+#             */
/*   Updated: 2023/08/04 15:59:28 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	amount_of_contacts = 0;
}

PhoneBook::~PhoneBook(void) {}

void	PhoneBook::add_contact()
{
	static int	index = 0;
	Contacts	contact;

	if (index == 8)
		index = 0;
	contact.new_contact(index);
	this->contacts[index] = contact;

	if (amount_of_contacts != 7)
		amount_of_contacts++;
	index++;
}

void	PhoneBook::display_all_contacts()
{
	for (int i = 0; i != amount_of_contacts; i++)
		contacts[i].display_contact();
}

void	PhoneBook::search_contact()
{
	display_all_contacts();
}
