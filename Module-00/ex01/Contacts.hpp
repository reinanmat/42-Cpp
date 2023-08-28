/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:07:28 by revieira          #+#    #+#             */
/*   Updated: 2023/08/27 20:02:59 by revieira         ###   ########.fr       */
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
		void		setIndex(int index);
		void		setPhoneNumber(std::string phoneNumber);
		void		setFirstName(std::string firstName);
		void		setLastName(std::string lastName);
		void		setNickname(std::string nickName);
		void		setDarkestSecret(std::string darkestSecret);
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
