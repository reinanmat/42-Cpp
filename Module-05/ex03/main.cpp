/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:53:10 by revieira          #+#    #+#             */
/*   Updated: 2023/12/05 16:35:33 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void)
{
	{
		std::cout << "TEST 1 (SUBJECT TEST)" << std::endl;
		Intern	someRandomIntern;
		AForm	*rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;

		delete rrf;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2" << std::endl;
		
		AForm		*a;
		AForm		*b;
		AForm		*c;
		Intern		niceIntern;
		Bureaucrat	marvin("Marvin", 1);

		a = niceIntern.makeForm("shrubbery creation", "Home");
		b = niceIntern.makeForm("robotomy request", "Marvin");
		c = niceIntern.makeForm("presidential pardon", "Me");

		std::cout << std::endl;
		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		std::cout << *c << std::endl;
		std::cout << std::endl;

		marvin.signForm(*a);
		marvin.signForm(*b);
		marvin.signForm(*c);

		std::cout << std::endl;
		marvin.executeForm(*a);
		std::cout << std::endl;
		marvin.executeForm(*b);
		std::cout << std::endl;
		marvin.executeForm(*c);
		std::cout << std::endl;

		std::cout << *a << std::endl;
		std::cout << *b << std::endl;
		std::cout << *c << std::endl;

		delete a;
		delete b;
		delete c;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3 (INVALID FORMS)" << std::endl;

		AForm	*a;
		AForm	*b;
		AForm	*c;
		Intern	someRandomIntern;
		
		a = someRandomIntern.makeForm("Invalid", "");
		b = someRandomIntern.makeForm("Valid?", "");
		c = someRandomIntern.makeForm("presidential robotomy", "");
	}
	return (0);
}
