/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:44:09 by revieira          #+#    #+#             */
/*   Updated: 2023/12/01 16:48:22 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Form::Form() : _name(""), _isSigned(false), _gradeToExecute(0), _gradeToSign(0)
{
	#ifdef DEBUG
		std::cout << BLU "Form: Default Constructor Called" RESET << std::endl;
	#endif
}

Form::Form(const Form &obj) : _name(""), _isSigned(false), _gradeToExecute(0), _gradeToSign(0)
{
	#ifdef DEBUG
		std::cout << BLU "Form: Copy Constructor Called" RESET << std::endl;
	#endif
	if (this != &obj)
		*this = obj;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), 
_isSigned(false), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign)
{
	#ifdef DEBUG
		std::cout << BLU "Form " << name << ": Constructor Called" RESET << std::endl;
	#endif
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw (GradeTooLowExpection());
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw (GradeTooHighExpection());
}

Form::~Form()
{
	#ifdef DEBUG
		std::cout << RED "Form: Destructor Called" RESET << std::endl;
	#endif
}

/* OPERATORS OVERLOADING */
Form	&Form::operator=(const Form &other) 
{
	#if DEBUG
		std::cout << CYN "Form: Copy Constructor Called" RESET << std::endl;
	#endif
	if (this != &other)
	{
		this->~Form();
		new(this) Form(other._name, other._gradeToSign, other._gradeToExecute);
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Form &obj)
{
	#ifdef DEBUG
		std::cout << CYN "Form: Insertion Operator Called" RESET << std::endl;
	#endif
	out << CYN;
	out << "====================Form====================" << std::endl;
	out << "Name:\t\t" << obj.getName() << std::endl;
	out << "Grade To Sign:\t"  << obj.getGradeToSign() << std::endl;
	out << "Grade To Exec:\t" << obj.getGradeToExecute() << std::endl;
	out << "Signed:\t\t" << (obj.getIsSigned() ? "It was signed" : "Was not signed");
	out << RESET;
	return (out);
}

/* GETTERS */
std::string	Form::getName(void) const
{
	return (this->_name);
}

int	Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

int	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

/* MEMBERS FUNCTIONS */
void	Form::beSigned(const Bureaucrat &b)
{
	#if DEBUG
		std::cout << MAG "Form: beSigned Member Function Called" RESET << std::endl;
	#endif
	if (b.getGrade() > this->_gradeToSign)
		throw (GradeTooLowExpection());
	else
		this->_isSigned = true;
}
