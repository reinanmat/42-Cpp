/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:53:19 by revieira          #+#    #+#             */
/*   Updated: 2023/12/01 17:14:07 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &other);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);

	private:
		int					_grade;
		const std::string	_name;
};

class GradeTooHighExpection : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Bureaucrat::exception : Grade is too high");
		}
		virtual ~GradeTooHighExpection() throw() {};
};

class GradeTooLowExpection : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Bureaucrat::exception : Grade is too low");
		}
		virtual ~GradeTooLowExpection() throw() {};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj);
