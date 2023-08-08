/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:07:28 by revieira          #+#    #+#             */
/*   Updated: 2023/08/08 15:42:46 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_H

# include <iostream>

class Contacts
{
	public:
		Contacts();
		~Contacts();
		void		setContact(int index, std::string *info);
		int			getIndex();
		int			getPhoneNumber();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getDarkestSecret();
		void		displayContact();
		Contacts&	operator=(Contacts other);
	private:
		int			_index;
		int			_phoneNumber;
		std::string	_firstName;
		std::string	_lastName;
		std::string _nickname;
		std::string	_darkestSecret;
};

#endif
