/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:39:26 by revieira          #+#    #+#             */
/*   Updated: 2023/07/28 17:36:19 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONECLASS_H 

# include "Contacts.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		void	addContact();
		void	searchContact();
		~PhoneBook(void);
	private:
		Contacts contacts[8];
};

#endif
