/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:18:08 by revieira          #+#    #+#             */
/*   Updated: 2023/11/29 15:41:25 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Animal::Animal()
{
	std::cout << BLU "Animal: Default Constructor Called" RESET << std::endl;
	this->type = "";
}

Animal::Animal(const Animal &obj)
{
	std::cout << BLU "Animal: Copy Constructor Called" RESET << std::endl;
	if (this != &obj)
		*this = obj;
}

Animal::~Animal()
{
	std::cout << RED "Animal: Destructor Called" RESET << std::endl;
}

/* OPERATORS OVERLOADING */
Animal	&Animal::operator=(Animal const &other)
{
	std::cout << CYN "Animal: Copy Assignment Operator Called" RESET << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

/* GETTERS AND SETTERS */
std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::setType(std::string type)
{
	this->type = type;
}

/* MEMBER FUNCTIONS */
void	Animal::makeSound(void) const
{
	std::cout << GRN "Default animal sound!" RESET << std::endl;
}
