/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:53:19 by revieira          #+#    #+#             */
/*   Updated: 2023/11/20 16:45:18 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat(int grade, std::string name);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &other);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);
		void		signForm(Form &f) const;

	private:
		int					_grade;
		const std::string	_name;
};

class GradeTooHighExpection : public std::exception
{
	public:
		GradeTooHighExpection()
		{
			_msgException = "Error: exception a very high grade was passed";
		} 
		virtual const char *what() const throw()
		{
			return (this->_msgException.c_str());
		}
		virtual ~GradeTooHighExpection() throw() {};
	private:
		std::string	_msgException;
};

class GradeTooLowExpection : public std::exception
{
	public:
		GradeTooLowExpection()
		{
			_msgException = "Error: exception a very low grade was passed";
		} 
		virtual const char *what() const throw()
		{
			return (this->_msgException.c_str());
		}
		virtual ~GradeTooLowExpection() throw() {};
	private:
		std::string	_msgException;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj);
