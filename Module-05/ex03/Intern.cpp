/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:37:48 by revieira          #+#    #+#             */
/*   Updated: 2023/12/05 16:41:21 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Intern::Intern()
{
	#ifdef DEBUG
		std::cout << BLU "Intern: Default Constructor Called" RESET << std::endl;
	#endif
}

Intern::Intern(const Intern &obj)
{
	#ifdef DEBUG
		std::cout << BLU "Intern: Copy Constructor Called" RESET << std::endl;
	#endif
	if (this != &obj)
		*this = obj;
}

Intern::~Intern()
{
	#ifdef DEBUG
		std::cout << RED "Intern: Destructor Called" RESET << std::endl;
	#endif
}

/* OPERATORS OVERLOADING */
Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

/* MEMBERS FUNCTIONS */
static int	getFormNumber(std::string formName)
{
	std::string	validForms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	for (int i = 0; i < 3; i++)
		if (formName == validForms[i])
			return(i + 1);
	return (-1);
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	int		formNumber;
	AForm	*formCreated;

	formCreated = NULL;
	formNumber = getFormNumber(formName);
	switch (formNumber) {
		case 1:
			std::cout << MAG "Intern creates Shrubbery Creation Form" RESET << std::endl;
			formCreated = new ShrubberyCreationForm(target);
			break ;
		case 2:
			std::cout << MAG "Intern creates Robotomy Request Form" RESET << std::endl;
			formCreated = new RobotomyRequestForm(target);
			break ;
		case 3:
			std::cout << MAG "Intern creates Presidential Pardon Form" RESET << std::endl;
			formCreated = new PresidentialPardonForm(target);
			break ;
		default:
			std::cout << RED "Error: Intern doesn't know "  << formName << " Form" RESET << std::endl;
			break;
	}
	return (formCreated);
}
