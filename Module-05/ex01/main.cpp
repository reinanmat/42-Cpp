/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:53:10 by revieira          #+#    #+#             */
/*   Updated: 2023/10/26 18:59:51 by revieira         ###   ########.fr       */
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
		Form	f = Form("Probably Something Very Important", 1, 1);
		std::cout << f << std::endl;
		try {
			Bureaucrat	b(150, "Someone Important");
			std::cout << b << std::endl;
			// Form	f = Form("Probably Something Very Important", 1, 1);
			// std::cout << f << std::endl;
			f.beSigned(b);
			std::cout << f << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			Bureaucrat	b(1, "Someone");
			std::cout << b << std::endl;
			// Form	f = Form("Probably Something Very Important", 1, 1);
			// std::cout << f << std::endl;
			f.beSigned(b);
			std::cout << f << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
