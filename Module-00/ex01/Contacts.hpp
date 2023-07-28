/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:07:28 by revieira          #+#    #+#             */
/*   Updated: 2023/07/28 18:40:05 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_H

# include <iostream>

class Contacts
{
	public:
		Contacts();
		~Contacts();
		void createContact(int index);
	private:
		int			index;
		int			phoneNumber;
		std::string	firstName;
		std::string	lastName;
		std::string nickname;
		std::string	darkestSecret;
};

#endif
