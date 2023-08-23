/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:07:28 by revieira          #+#    #+#             */
/*   Updated: 2023/08/23 17:39:02 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_H
# define CONTACTS_H

# include <iostream>
# include <iomanip>
# include <string>

class Contacts
{
	public:
		Contacts();
		~Contacts();
		void		setContact(int index, std::string info[5]);
		int			getIndex();
		std::string	getPhoneNumber();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickname();
		std::string	getDarkestSecret();
		void		displaySimplifiedContact();
		void		displayFullContact();
		Contacts&	operator=(Contacts other);
	private:
		int			_index;
		std::string	_phoneNumber;
		std::string	_firstName;
		std::string	_lastName;
		std::string _nickname;
		std::string	_darkestSecret;
};

#endif
