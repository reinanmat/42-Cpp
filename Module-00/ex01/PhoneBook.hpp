/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:39:26 by revieira          #+#    #+#             */
/*   Updated: 2023/10/20 18:07:15 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include "Contacts.hpp"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
#define CLEANWINDOW "\e[1;1H\e[2J"

class PhoneBook
{
	public:
		PhoneBook();
		PhoneBook(const PhoneBook &obj);
		~PhoneBook();
		PhoneBook	&operator=(const PhoneBook &cpy);
		int			getAmountOfContacts() const;
		Contacts	getContact(int index) const;
		void		setAmountOfContacts(int amount);
		void		addContact();
		void		searchContact() const;
		void		displayAllContacts() const;
		void		displayContact(int index) const;

	private:
		int			_amountOfContacts;
		Contacts	_contacts[8];
};

int			checkEmptyField(std::string	str);
int			checkNumber(std::string number);
int			checkUnicodeChar(std::string str);
std::string	getInput(std::string key);
