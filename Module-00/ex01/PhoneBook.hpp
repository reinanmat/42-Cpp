/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:39:26 by revieira          #+#    #+#             */
/*   Updated: 2023/08/27 20:44:42 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <cstdlib>
# include "Contacts.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		int			getAmountOfContacts();
		Contacts	getContact(int index);
		void		setAmountOfContacts(int amount);
		void		addContact();
		void		searchContact();
		void		displayAllContacts();
		void		displayContact(int index);
	private:
		int			_amountOfContacts;
		Contacts	_contacts[8];
};

#endif
