/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:07:28 by revieira          #+#    #+#             */
/*   Updated: 2023/08/04 15:26:00 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_H

# include <iostream>

class Contacts
{
	public:
		Contacts();
		~Contacts();
		void		new_contact(int index);
		void		display_contact();
		int			get_number();
		std::string	get_info(std::string info);
		Contacts& operator=(Contacts other);
	private:
		int			index;
		int			phone_number;
		std::string	first_name;
		std::string	last_name;
		std::string nickname;
		std::string	darkest_secret;
};

#endif
