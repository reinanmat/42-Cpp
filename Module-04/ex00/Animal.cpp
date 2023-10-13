/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:18:08 by revieira          #+#    #+#             */
/*   Updated: 2023/10/13 18:49:30 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Animal::Animal()
{
	std::cout << "Animal: Default Constructor Called" << std::endl;
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Animal: Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor Called" << std::endl;
}

/* OPERATORS OVERLOADING */
Animal	&Animal::operator=(Animal const &other)
{
	std::cout << "Animal: Copy Assignment Operator Called" << std::endl;
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
void	Animal::makeSound(void)
{
}
