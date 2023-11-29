/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:18:08 by revieira          #+#    #+#             */
/*   Updated: 2023/11/29 18:31:22 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
AAnimal::AAnimal()
{
	std::cout << BLU "AAnimal: Default Constructor Called" RESET << std::endl;
	this->type = "";
}

AAnimal::AAnimal(const AAnimal &obj)
{
	std::cout << BLU "AAnimal: Copy Constructor Called" RESET << std::endl;
	if (this != &obj)
		*this = obj;
}

AAnimal::~AAnimal()
{
	std::cout << RED "AAnimal: Destructor Called" RESET << std::endl;
}

/* OPERATORS OVERLOADING */
AAnimal	&AAnimal::operator=(AAnimal const &other)
{
	std::cout << CYN "AAnimal: Copy Assignment Operator Called" RESET << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

/* GETTERS AND SETTERS */
std::string	AAnimal::getType(void) const
{
	return (this->type);
}

void	AAnimal::setType(std::string type)
{
	this->type = type;
}

/* MEMBER FUNCTIONS */
void	AAnimal::makeSound(void) const
{
	std::cout << GRN "Default animal sound!" RESET << std::endl;
}
