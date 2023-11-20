/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:44:18 by revieira          #+#    #+#             */
/*   Updated: 2023/11/20 15:28:50 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const Form &obj);
		Form(std::string name, int gradeToSign, int gradeToExecute);
		~Form();
		Form		&operator=(const Form &obj);
		std::string	getName(void) const;
		int			getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		void		beSigned(const Bureaucrat &b);
	
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToExecute;
		const int			_gradeToSign;
};

std::ostream	&operator<<(std::ostream &out, const Form &obj);
