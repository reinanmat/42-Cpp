/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:53:10 by revieira          #+#    #+#             */
/*   Updated: 2023/12/05 15:15:34 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

static void	tryCreateAForm(std::string name, int gradeToSign, int gradeToExec)
{
	std::cout << "Trying to create the Form: " << name;
	std::cout << ", " << gradeToSign << " grade to sign";
	std::cout << " and " << gradeToExec << " grade to execute..." << std::endl;
	try {
		Form a(name, gradeToSign, gradeToExec);
		std::cout << GRN "Form created" RESET << std::endl;
		std::cout << a << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "It was not possible to create the Form " << name
			<< " because " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	{
		std::cout << "TEST 1" << std::endl;
		tryCreateAForm("InvalidForm1", 151, 151);
		tryCreateAForm("InvalidForm2", 0, 0);
		tryCreateAForm("InvalidForm3", 0, 100);
		tryCreateAForm("InvalidForm4", 100, 0);
		tryCreateAForm("ValidForm1", 1, 1);
		tryCreateAForm("ValidForm2", 75, 1);
		tryCreateAForm("ValidForm3", 15, 12);
		tryCreateAForm("ValidForm4", 150, 150);
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2" << std::endl;

		Bureaucrat	b1("Someone Important", 1);
		Bureaucrat	b2("Bob", 150);
		Form		form1 = Form("Probably Something Very Important", 1, 1);
		Form		form2 = Form("Nothing Important", 150, 150);

		std::cout << b2 << std::endl;
		std::cout << b1 << std::endl;
		std::cout << std::endl;
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << std::endl;

		b1.signForm(form1);
		b1.signForm(form2);
		b2.signForm(form1);
		b2.signForm(form2);
		std::cout << std::endl;
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3" << std::endl;

		Form		f("Proclamation Of Something", 50, 50);
		Bureaucrat	b1("Anne", 52);
		Bureaucrat	b2("Bob", 51);
		Bureaucrat	b3("Viktor", 50);
		Bureaucrat	b4("Francis", 49);

		std::cout << f << std::endl;
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		std::cout << b4 << std::endl;

		b1.signForm(f);
		b2.signForm(f);
		b3.signForm(f);
		b4.signForm(f);
	}
	return (0);
}
