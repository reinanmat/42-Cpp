/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:53:10 by revieira          #+#    #+#             */
/*   Updated: 2023/11/20 17:34:49 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)
{
	{
		std::cout << "TEST 1" << std::endl;
		try {
			Form	a("InvalidForm", 151, 151);
			std::cout << a << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Form	b("InvalidForm", 0, 0);	
			std::cout << b << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Form	c("ValidForm", 75, 75);	
			std::cout << c << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "TEST 2" << std::endl;

		Bureaucrat	b(1, "Someone Important");
		Bureaucrat	bob(150, "Bob");
		Form		f = Form("Probably Something Very Important", 1, 1);

		std::cout << f << std::endl;
		std::cout << b << std::endl;
		std::cout << bob << std::endl;
		// f.beSigned(bob);
		f.beSigned(b);
		f.beSigned(b);
		std::cout << f << std::endl;
	}
	return (0);
}
