/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:39:26 by revieira          #+#    #+#             */
/*   Updated: 2023/08/08 15:38:40 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONECLASS_H 

# include <iostream>
# include "Contacts.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		int		getAmountOfContacts();
		void	setAmountOfContacts(int amount);
		void	addContact(int index, std::string info[6]);
		void	displayContact(int index);
		void	displayAllContacts();
	private:
		int			_amountOfContacts;
		Contacts	_contacts[8];
};

#endif
