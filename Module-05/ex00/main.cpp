/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:53:10 by revieira          #+#    #+#             */
/*   Updated: 2023/12/01 17:36:16 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void	TryCreateABureaucrat(std::string name, int grade)
{
	std::cout << "Trying to create the Bureaucrat: " << name;
	std::cout << ", with grade: " << grade << std::endl;
	try {
		Bureaucrat a(name, grade);
		std::cout << GRN "Bureaucrat created" RESET << std::endl;
		std::cout << a << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "It was not possible to create the Bureaucrat " << name 
			<< " because " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	{
		std::cout << "TEST 1" << std::endl;
		TryCreateABureaucrat("Bob", 151);
		TryCreateABureaucrat("Anne", 0);
		TryCreateABureaucrat("Viktor", 150);
		TryCreateABureaucrat("Marvin", 1);
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2 (INCREMENT GRADE)" << std::endl;
		Bureaucrat a("BureaucratA", 75);
		std::cout << a << std::endl;
		try {
			for (int i = 0; i < 10; i++) {
				a.incrementGrade();
				std::cout << a << std::endl;
			}
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3 (DECREMENT GRADE)" << std::endl;
		Bureaucrat b("BureaucratB", 75);
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
