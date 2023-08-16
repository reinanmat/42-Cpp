/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:39:26 by revieira          #+#    #+#             */
/*   Updated: 2023/08/16 17:16:43 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKCLASS_H

# include "Contacts.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		int			getAmountOfContacts();
		Contacts	getContact(int index);
		void		setAmountOfContacts(int amount);
		void		addContact(int index, std::string info[5]);
		int			displayContacts();
		int			displayContacts(int index);
	private:
		int			_amountOfContacts;
		Contacts	_contacts[8];
};

#endif
