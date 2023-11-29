/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:51:10 by revieira          #+#    #+#             */
/*   Updated: 2023/11/29 17:41:57 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Cat::Cat() : Animal()
{
	std::cout << BLU "Cat: Default Constructor Called" RESET << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << BLU "Cat: Copy Constructor Called" RESET << std::endl;
	if (this != &obj)
		*this = obj;
}

Cat::~Cat()
{
	std::cout << RED "Cat: Destructor Called" RESET << std::endl;
	delete this->_brain;
}

/* OPERATORS OVERLOADING */
Cat	&Cat::operator=(Cat const &other)
{
	std::cout << CYN "Cat: Copy Assignment Operator Called" RESET << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->_brain = other._brain;
	}
	return (*this);
}

/* MEMBER FUNCTIONS */
void  Cat::makeSound(void) const
{
	std::cout << GRN "The cat say: Meow!" RESET << std::endl;
}
