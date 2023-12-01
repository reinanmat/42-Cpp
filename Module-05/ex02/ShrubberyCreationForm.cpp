/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:37:31 by revieira          #+#    #+#             */
/*   Updated: 2023/12/01 18:51:37 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Robotomy Request Form", 145, 137)
{
	this->_target = "";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Robotomy Request Form", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm("Robotomy Request Form", 145, 137)
{
	if (this != &obj)
		*this = obj;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor)
{
	if (this->getIsSigned() == false)
		return ;
}
