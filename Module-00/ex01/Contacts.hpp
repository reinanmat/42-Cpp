/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:07:28 by revieira          #+#    #+#             */
/*   Updated: 2023/10/20 18:06:25 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Contacts
{
	public:
		Contacts();
		Contacts(const Contacts &obj);
		~Contacts();
		Contacts	&operator=(const Contacts &other);
		int			getIndex() const;
		std::string	getPhoneNumber() const;
		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getDarkestSecret();
		void		setIndex(int index);
		void		setPhoneNumber(std::string phoneNumber);
		void		setFirstName(std::string firstName);
		void		setLastName(std::string lastName);
		void		setNickname(std::string nickName);
		void		setDarkestSecret(std::string darkestSecret);
		void		displaySimplifiedContact() const;
		void		displayFullContact() const;

	private:
		int			_index;
		std::string	_phoneNumber;
		std::string	_firstName;
		std::string	_lastName;
		std::string _nickname;
		std::string	_darkestSecret;
};
