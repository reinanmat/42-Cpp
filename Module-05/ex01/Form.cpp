/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:44:09 by revieira          #+#    #+#             */
/*   Updated: 2023/11/20 17:29:29 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Form::Form() : _name(""), _isSigned(false), _gradeToExecute(0), _gradeToSign(0)
{
	#ifdef DEBUG
		std::cout << "Form: Default Constructor Called" << std::endl;
	#endif
}

Form::Form(const Form &obj) : _name(""), _isSigned(false), _gradeToExecute(0), _gradeToSign(0)
{
	#ifdef DEBUG
		std::cout << "Form: Copy Constructor Called" << std::endl;
	#endif
	if (this != &obj)
		*this = obj;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), 
	_isSigned(false), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign)
{
	#ifdef DEBUG
		std::cout << "Form " << name << ": Constructor Called" << std::endl;
	#endif
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw (GradeTooLowExpection());
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw (GradeTooHighExpection());
}

Form::~Form()
{
	#ifdef DEBUG
		std::cout << "Form: Destructor Called" << std::endl;
	#endif
}

/* OPERATORS OVERLOADING */
Form	&Form::operator=(const Form &other) 
{
	#if DEBUG
		std::cout << "Form: Copy Constructor Called" << std::endl;
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
		std::cout << "Form: Insertion Operator Called" << std::endl;
	#endif
	out << "Form: " << obj.getName() << std::endl;
	out << "Grade to sign: "  << obj.getGradeToSign() << std::endl;
	out << "Grade to execute: " << obj.getGradeToExecute() << std::endl;
	out << "Signed: " << (obj.getIsSigned() ? "it was signed" : "was not signed");
	return (out);
}

/* GETTERS */
std::string	Form::getName(void) const
{
	#if DEBUG
		std::cout << "Form: getName Member Function Called" << std::endl;
	#endif
	return (this->_name);
}

int	Form::getGradeToSign(void) const
{
	#if DEBUG
		std::cout << "Form: getGradeToSign Member Function Called" << std::endl;
	#endif
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute(void) const
{
	#if DEBUG
		std::cout << "Form: getGradeToExecute Member Function Called" << std::endl;
	#endif
	return (this->_gradeToExecute);
}

int	Form::getIsSigned(void) const
{
	#if DEBUG
		std::cout << "Form: getIsSing Member Function Called" << std::endl;
	#endif
	return (this->_isSigned);
}

/* MEMBERS FUNCTIONS */
void	Form::beSigned(const Bureaucrat &b)
{
	#if DEBUG
		std::cout << "Form: beSigned Member Function Called" << std::endl;
	#endif
	if (this->_isSigned) {
		throw ;
	} else if (b.getGrade() < this->_gradeToSign) {
		throw (GradeTooLowExpection());
	} else {
		this->_isSigned = true;
	}
}
