/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:44:09 by revieira          #+#    #+#             */
/*   Updated: 2023/12/01 19:03:11 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
AForm::AForm() : _name(""), _isSigned(false), _gradeToExecute(0), _gradeToSign(0)
{
	#ifdef DEBUG
		std::cout << BLU "AForm: Default Constructor Called" RESET << std::endl;
	#endif
}

AForm::AForm(const AForm &obj) : _name(""), _isSigned(false), _gradeToExecute(0), _gradeToSign(0)
{
	#ifdef DEBUG
		std::cout << BLU "AForm: Copy Constructor Called" RESET << std::endl;
	#endif
	if (this != &obj)
		*this = obj;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), 
_isSigned(false), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign)
{
	#ifdef DEBUG
		std::cout << BLU "AForm " << name << ": Constructor Called" RESET << std::endl;
	#endif
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw (GradeTooLowExpection());
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw (GradeTooHighExpection());
}

AForm::~AForm()
{
	#ifdef DEBUG
		std::cout << RED "AForm: Destructor Called" RESET << std::endl;
	#endif
}

/* OPERATORS OVERLOADING */
AForm	&AForm::operator=(const AForm &other) 
{
	#if DEBUG
		std::cout << CYN "AForm: Copy Constructor Called" RESET << std::endl;
	#endif
	if (this != &other)
	{
		this->~AForm();
		new(this) AForm(other._name, other._gradeToSign, other._gradeToExecute);
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const AForm &obj)
{
	#ifdef DEBUG
		std::cout << CYN "AForm: Insertion Operator Called" RESET << std::endl;
	#endif
	out << CYN;
	out << "====================AForm====================" << std::endl;
	out << "Name:\t\t" << obj.getName() << std::endl;
	out << "Grade To Sign:\t"  << obj.getGradeToSign() << std::endl;
	out << "Grade To Exec:\t" << obj.getGradeToExecute() << std::endl;
	out << "Signed:\t\t" << (obj.getIsSigned() ? "It was signed" : "Was not signed");
	out << RESET;
	return (out);
}

/* GETTERS */
std::string	AForm::getName(void) const
{
	return (this->_name);
}

int	AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

int	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

/* MEMBERS FUNCTIONS */
void	AForm::beSigned(const Bureaucrat &b)
{
	#if DEBUG
		std::cout << MAG "AForm: beSigned Member Function Called" RESET << std::endl;
	#endif
	if (b.getGrade() > this->_gradeToSign)
		throw (GradeTooLowExpection());
	else
		this->_isSigned = true;
}

void	execute(Bureaucrat const &executor)
{}
