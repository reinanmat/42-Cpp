/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:00:32 by revieira          #+#    #+#             */
/*   Updated: 2023/11/20 17:04:03 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>

/* CONSTRUCTOS AND DESTRUCTOR */
Bureaucrat::Bureaucrat() : _grade(150)
{
	#ifdef DEBUG
		std::cout << "Bureaucrat: Default Constructor Called" << std::endl;
	#endif
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	#ifdef DEBUG
		std::cout << "Bureaucrat: Copy Constructor Called" << std::endl;
	#endif
	if (this != &obj)
		*this = obj;
}

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name)
{
	#ifdef DEBUG
		std::cout << "Bureaucrat " << name << ": Constructor Called" << std::endl;
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
		std::cout << "Bureaucrat: Destructor Called" << std::endl;
	#endif
}

/* GETTERS */
std::string	Bureaucrat::getName(void) const
{
	#ifdef DEBUG
		std::cout << "Bureaucrat: getName Member Function Called" << std::endl;
	#endif
	return this->_name;
}

int	Bureaucrat::getGrade(void) const
{
	#ifdef DEBUG
		std::cout << "Bureaucrat: getGrade Member Function Called" << std::endl;
	#endif
	return this->_grade;
}

/* OPERATORS OVERLOADING */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	#ifdef DEBUG
		std::cout << "Bureaucrat: Copy Assignment Operator Called" << std::endl;
	#endif
	if (this != &other)
	{
		this->~Bureaucrat();
		new(this) Bureaucrat(other._grade, other._name);
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj)
{
	#ifdef DEBUG
		std::cout << "Bureaucrat: Insertion Operator Called" << std::endl;
	#endif
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (out);
}

/* MEMBER FUNCTIONS */
void	Bureaucrat::incrementGrade(void)
{
	#ifdef DEBUG
		std::cout << "Bureaucrat: incrementGrade Member Function Called" << std::endl;
	#endif
	if (this->_grade - 1 < 1)
		throw(GradeTooHighExpection());
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	#ifdef DEBUG
		std::cout << "Bureaucrat: decrementGrade Member Function Called" << std::endl;
	#endif
	if (this->_grade + 1 > 150)
		throw(GradeTooLowExpection());
	else
		this->_grade++;
}

void	Bureaucrat::signForm(Form &f) const
{
	try {
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->_name << " couldn’t sign " << f.getName() << "because ahhhhhhhhhhhhh" << std::endl;
	}
}
