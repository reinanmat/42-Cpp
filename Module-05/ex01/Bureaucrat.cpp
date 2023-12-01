/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:00:32 by revieira          #+#    #+#             */
/*   Updated: 2023/12/01 17:39:41 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

/* CONSTRUCTOS AND DESTRUCTOR */
Bureaucrat::Bureaucrat() : _grade(150)
{
	#ifdef DEBUG
		std::cout << BLU "Bureaucrat: Default Constructor Called" RESET << std::endl;
	#endif
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	#ifdef DEBUG
		std::cout << BLU "Bureaucrat: Copy Constructor Called" RESET << std::endl;
	#endif
	if (this != &obj)
		*this = obj;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	#ifdef DEBUG
		std::cout << BLU "Bureaucrat " << name << ": Constructor Called" RESET << std::endl;
	#endif
	if (grade < 1)
		throw(GradeTooHighExpection());
	else if (grade > 150)
		throw(GradeTooLowExpection());
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	#ifdef DEBUG
		std::cout << RED "Bureaucrat: Destructor Called" RESET << std::endl;
	#endif
}

/* GETTERS */
std::string	Bureaucrat::getName(void) const
{
	return this->_name;
}

int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

/* OPERATORS OVERLOADING */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	#ifdef DEBUG
		std::cout << CYN "Bureaucrat: Copy Assignment Operator Called" RESET << std::endl;
	#endif
	if (this != &other)
	{
		this->~Bureaucrat();
		new(this) Bureaucrat(other._name, other._grade);
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << CYN;
	out <<  "=================Bureaucrat=================" << std::endl;
	out << "Name:\t" << obj.getName() << std::endl;
	out << "Grade:\t" << obj.getGrade() << RESET;
	out << RESET;
	return (out);
}

/* MEMBER FUNCTIONS */
void	Bureaucrat::incrementGrade(void)
{
	#ifdef DEBUG
		std::cout << MAG "Bureaucrat: incrementGrade Member Function Called" RESET << std::endl;
	#endif
	if (this->_grade - 1 < 1)
		throw(GradeTooHighExpection());
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	#ifdef DEBUG
		std::cout << MAG "Bureaucrat: decrementGrade Member Function Called" RESET << std::endl;
	#endif
	if (this->_grade + 1 > 150)
		throw(GradeTooLowExpection());
	else
		this->_grade++;
}

void	Bureaucrat::signForm(Form &f) const
{
	#ifdef DEBUG
		std::cout << MAG "Bureaucrat: signForm Member Function Called" RESET << std::endl;
	#endif
	try {
		f.beSigned(*this);
		std::cout << GRN "Bureaucrat " << this->_name << " signed Form \""
			<< f.getName() << "\"" RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED "Bureaucrat " << this->_name << " couldn’t sign \""
			<< f.getName() <<"\" because " << e.what() << RESET << std::endl;
	}
}
