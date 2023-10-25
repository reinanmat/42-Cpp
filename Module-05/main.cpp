/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:53:10 by revieira          #+#    #+#             */
/*   Updated: 2023/10/25 17:39:37 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	{
		std::cout << "TEST 1" << std::endl;
		try {
			Bureaucrat a(0, "BureaucratA");
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			Bureaucrat b(151, "BureaucratB");
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			Bureaucrat c(75, "BureaucratC");
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "TEST 2" << std::endl;
		Bureaucrat a(75, "BureaucratA");
		std::cout << a << std::endl;
		try {
			for (int i = 0; i < 10; i++) {
				a.incrementGrade();
				std::cout << a << std::endl;
			}
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		Bureaucrat b(75, "BureaucratB");
		std::cout << a << std::endl;
		try {
			for (int i = 0; i < 10; i++) {
				b.decrementGrade();
				std::cout << b << std::endl;
			}
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	return (0);
}
