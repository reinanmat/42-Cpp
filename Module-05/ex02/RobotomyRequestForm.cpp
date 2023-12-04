/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:35:22 by revieira          #+#    #+#             */
/*   Updated: 2023/12/04 15:54:32 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm("Robotomy Request", 72, 45)
{
	if (this != &obj)
		*this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::checkExecute(executor);
	std::cout << "Initiating robotomy procedure on " << this->_target << "..." << std::endl;
	std::cout << "* * * drilling noises * * *" << std::endl;
	std::srand(time(0));
	bool sucess = rand() % 2 == 0;
	if (sucess)
		std::cout << GRN << this->_target << " has been robotomized successfully." RESET << std::endl;
	else
		std::cout << RED << this->_target << " failed to be robotized" RESET << std::endl;
	
}
