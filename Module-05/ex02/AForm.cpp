/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:44:09 by revieira          #+#    #+#             */
/*   Updated: 2023/12/05 14:34:08 by revieira         ###   ########.fr       */
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
		throw (AForm::GradeTooLowExpection());
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw (AForm::GradeTooHighExpection());
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
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const AForm &obj)
{
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

const char *AForm::GradeTooHighExpection::what() const throw()
{
	return ("AForm::exception : Grade is too high");
}

const char *AForm::GradeTooLowExpection::what() const throw()
{
	return ("AForm::exception : Grade is too low");
}

const char *AForm::FormIsNotSigned::what() const throw()
{
	return ("AForm::exception : Form is not signed");
}


void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->_gradeToSign)
		throw (AForm::GradeTooLowExpection());
	else
		this->_isSigned = true;
}

void	AForm::checkExecute(const Bureaucrat &b) const
{
	if (!this->_isSigned)
		throw (AForm::FormIsNotSigned());
	else if (b.getGrade() > this->_gradeToExecute)
		throw (AForm::GradeTooLowExpection());
}
