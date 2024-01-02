/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:53:10 by revieira          #+#    #+#             */
/*   Updated: 2023/12/20 14:37:04 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	{
		std::cout << "TEST 1 (CHECKING GRADES)" << std::endl;
		AForm *a = new ShrubberyCreationForm("tree");
		AForm *b = new RobotomyRequestForm("tree");
		AForm *c = new PresidentialPardonForm("tree");
		
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		std::cout << *c << std::endl;

		delete a;
		delete b;
		delete c;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2" << std::endl;
		Bureaucrat				marvin("marvin", 1);
		ShrubberyCreationForm	formA("tree");
		RobotomyRequestForm		formB("bob");
		PresidentialPardonForm	formC("me");

		std::cout << marvin << std::endl;

		marvin.signForm(formA);
		marvin.signForm(formB);
		marvin.signForm(formC);
		std::cout << std::endl;
		std::cout << formA << std::endl;
		std::cout << formB << std::endl;
		std::cout << formC << std::endl;
		std::cout << std::endl;
		marvin.executeForm(formA);
		std::cout << std::endl;
		marvin.executeForm(formB);
		std::cout << std::endl;
		marvin.executeForm(formC);
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3" << std::endl;
		
		Bureaucrat				marvin("Marvin", 1);
		Bureaucrat				bob("Bob", 150);
		ShrubberyCreationForm	formA("Tree");
		RobotomyRequestForm		formB("Bob");
		PresidentialPardonForm	formC("Me");

		std::cout << marvin << std::endl;
		std::cout << bob << std::endl;
		std::cout << std::endl;

		bob.executeForm(formA);
		bob.executeForm(formB);
		bob.executeForm(formC);
		std::cout << std::endl;
		bob.signForm(formA);
		bob.signForm(formB);
		bob.signForm(formC);
		std::cout << std::endl;
		bob.executeForm(formA);
		bob.executeForm(formB);
		bob.executeForm(formC);
		std::cout << std::endl;
		marvin.signForm(formA);
		marvin.signForm(formB);
		marvin.signForm(formC);
		std::cout << std::endl;
		bob.executeForm(formA);
		bob.executeForm(formB);
		bob.executeForm(formC);
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 4" << std::endl;
		
		Bureaucrat				bob("Bob", 25);
		PresidentialPardonForm	form("Bob");

		std::cout << bob << std::endl;
		std::cout << form << std::endl;

		bob.signForm(form);
		bob.executeForm(form);
		std::cout << form << std::endl;
	}
	return (0);
}
