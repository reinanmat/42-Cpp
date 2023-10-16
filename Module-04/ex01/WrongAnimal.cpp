/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:54:16 by revieira          #+#    #+#             */
/*   Updated: 2023/10/16 15:12:42 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal: Default Constructor Called" << std::endl;
	this->type = "";
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "WrongAnimal: Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor Called" << std::endl;
}

/* OPERATORS OVERLOADING */
WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &other)
{
	std::cout << "WrongAnimal: Copy Assignment Operator Called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

/* GETTERS AND SETTERS */
std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::setType(std::string type)
{
	this->type = type;
}

/* MEMBER FUNCTIONS */
void	WrongAnimal::makeSound(void) const
{
	std::cout << "Default Wrong Animal Sound!" << std::endl;
}
