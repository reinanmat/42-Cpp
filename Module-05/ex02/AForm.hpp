/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:44:18 by revieira          #+#    #+#             */
/*   Updated: 2023/12/04 17:42:49 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const AForm &obj);
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		virtual ~AForm();
		AForm			&operator=(const AForm &obj);
		std::string		getName(void) const;
		int				getIsSigned(void) const;
		int				getGradeToSign(void) const;
		int				getGradeToExecute(void) const;
		void			beSigned(const Bureaucrat &b);
		virtual void	checkExecute(const Bureaucrat &b) const;
		virtual void	execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighExpection : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowExpection : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormIsNotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToExecute;
		const int			_gradeToSign;

};

std::ostream	&operator<<(std::ostream &out, const AForm &obj);
