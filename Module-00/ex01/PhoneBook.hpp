/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:39:26 by revieira          #+#    #+#             */
/*   Updated: 2023/08/04 15:59:12 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONECLASS_H 

# include <iostream>
# include "Contacts.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		void	add_contact();
		void	display_all_contacts();
		void	search_contact();
		~PhoneBook();
	private:
		int			amount_of_contacts;
		Contacts	contacts[8];
};

#endif
