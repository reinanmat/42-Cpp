/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:00:32 by revieira          #+#    #+#             */
/*   Updated: 2023/10/25 17:36:18 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* CONSTRUCTOS AND DESTRUCTOR */
Bureaucrat::Bureaucrat() 
{
	std::cout << "Bureaucrat: Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	std::cout << "Bureaucrat: Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name)
{
	std::cout << "Bureaucrat " << name << ": Constructor Called" << std::endl;
	if (grade < 1)
		throw(GradeTooHighExpection(*this));
	else if (grade > 150)
		throw(GradeTooLowExpection(*this));
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: Destructor Called" << std::endl;
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
	std::cout << "Bureaucrat: Copy Assignment Operator Called" << std::endl;
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj)
{
	std::cout << "Bureaucrat: Insertion Operator Called" << std::endl;
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (out);
}

/* MEMBER FUNCTIONS */
void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
		throw(GradeTooHighExpection(*this));
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw(GradeTooLowExpection(*this));
	else
		this->_grade++;
}
