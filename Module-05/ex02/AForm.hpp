/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:44:18 by revieira          #+#    #+#             */
/*   Updated: 2023/12/01 19:02:58 by revieira         ###   ########.fr       */
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
		virtual void	execute(Bureaucrat const &executor) = 0;
	
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToExecute;
		const int			_gradeToSign;
};

std::ostream	&operator<<(std::ostream &out, const AForm &obj);
