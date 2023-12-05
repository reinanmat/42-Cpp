/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:25:10 by revieira          #+#    #+#             */
/*   Updated: 2023/12/05 14:59:54 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* CONSTRUCTOS AND DESTRUCTOR */
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), _target("default")
{
	#ifdef DEBUG
		std::cout << BLU "PresidentialPardonForm: Default Constructor Called" RESET << std::endl;
	#endif
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), _target(target)
{
	#ifdef DEBUG
		std::cout << BLU "PresidentialPardonForm " << target << ": Constructor Called" RESET << std::endl;
	#endif
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm("Presidential Pardon", 25, 5)
{
	#ifdef DEBUG
		std::cout << BLU "PresidentialPardonForm: Copy Constructor Called" RESET << std::endl;
	#endif
	if (this != &obj)
		*this = obj;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	#ifdef DEBUG
		std::cout << RED "PresidentialPardonForm: Destructor Called" RESET << std::endl;
	#endif
}

/* OPERATORS OVERLOADING */
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

/* MEMBER FUNCTIONS */
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::checkExecute(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
