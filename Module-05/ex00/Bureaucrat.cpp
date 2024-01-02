/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:00:32 by revieira          #+#    #+#             */
/*   Updated: 2023/12/20 14:49:16 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* CONSTRUCTOS AND DESTRUCTOR */
Bureaucrat::Bureaucrat() : _grade(150), _name("")
{
	#ifdef DEBUG
		std::cout << BLU "Bureaucrat: Default Constructor Called" RESET << std::endl;
	#endif
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	#ifdef DEBUG
		std::cout << BLU "Bureaucrat " << name << ": Constructor Called" RESET << std::endl;
	#endif
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighExpection());
	else if (grade > 150)
		throw(Bureaucrat::GradeTooLowExpection());
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	#ifdef DEBUG
		std::cout << BLU "Bureaucrat: Copy Constructor Called" RESET << std::endl;
	#endif
	if (this != &obj)
		*this = obj;
}

Bureaucrat::~Bureaucrat()
{
	#ifdef DEBUG
		std::cout << RED "Bureaucrat: Destructor Called" RESET << std::endl;
	#endif
}

/* OPERATORS OVERLOADING */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->~Bureaucrat();
		new(this) Bureaucrat(other._name, other._grade);
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj)
{
	out << CYN << obj.getName() << ", bureaucrat grade "
		<< obj.getGrade() << RESET;
	return (out);
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

/* MEMBER FUNCTIONS */
const char *Bureaucrat::GradeTooHighExpection::what() const throw()
{
	return ("Bureaucrat::exception : Grade is too high");
}

const char *Bureaucrat::GradeTooLowExpection::what() const throw()
{
	return ("Bureaucrat::exception : Grade is too low");
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
		throw(Bureaucrat::GradeTooHighExpection());
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw(Bureaucrat::GradeTooLowExpection());
	else
		this->_grade++;
}
