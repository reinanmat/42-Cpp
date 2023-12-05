/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:35:22 by revieira          #+#    #+#             */
/*   Updated: 2023/12/05 14:47:50 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* CONSTRUCTOS AND DESTRUCTOR */
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), _target("default")
{
	#ifdef DEBUG
		std::cout << BLU "RobotomyRequestForm: Default Constructor Called" RESET << std::endl;
	#endif
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), _target(target)
{
	#ifdef DEBUG
		std::cout << BLU "RobotomyRequestForm " << target << ": Constructor Called" RESET << std::endl;
	#endif
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm("Robotomy Request", 72, 45)
{
	#ifdef DEBUG
		std::cout << BLU "RobotomyRequestForm: Copy Constructor Called" RESET << std::endl;
	#endif
	if (this != &obj)
		*this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	#ifdef DEBUG
		std::cout << RED "RobotomyRequestForm: Destructor Called" RESET << std::endl;
	#endif
}

/* OPERATORS OVERLOADING */
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

/* MEMBER FUNCTIONS */
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
