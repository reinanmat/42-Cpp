/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:46:04 by revieira          #+#    #+#             */
/*   Updated: 2023/07/28 18:46:02 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	startPhone(void)
{
	int			chosen;
	PhoneBook	phone;
	
	std::cout << "Welcome to my Phone" << std::endl;
	while (1)
	{
		std::cout << "1.ADD" << std::endl;
		std::cout << "2.SEARCH" << std::endl;
		std::cout << "3.EXIT" << std::endl;

		std::cin >> chosen;
		if (chosen == 1)
			phone.addContact();
		else if (chosen == 2){}
			/* search_contact() */
		else if (chosen == 3)
			break ;
		else
			std::cout << "Invalid option please select one of the options below" << std::endl;
	}
}

int	main(void)
{
	startPhone();
	return (0);
}
