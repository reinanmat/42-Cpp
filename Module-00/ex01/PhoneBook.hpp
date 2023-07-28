/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:39:26 by revieira          #+#    #+#             */
/*   Updated: 2023/07/28 18:46:35 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONECLASS_H 

# include <iostream>
# include "Contacts.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		void	addContact();
		void	searchContact(int index);
		~PhoneBook(void);
	private:
		Contacts contacts[8];
};

#endif
