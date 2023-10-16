/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:51:10 by revieira          #+#    #+#             */
/*   Updated: 2023/10/16 16:37:53 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Cat::Cat() : Animal()
{
	std::cout << "Cat: Default Constructor Called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	std::cout << "Cat: Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor Called" << std::endl;
	delete this->_brain;
}

/* OPERATORS OVERLOADING */
Cat	&Cat::operator=(Cat const &other)
{
	std::cout << "Cat: Copy Assignment Operator Called" << std::endl;
	if (this != &other)
		this->type = type;
	return (*this);
}

/* MEMBER FUNCTIONS */
void  Cat::makeSound(void) const
{
	std::cout << "The cat say: Meow!" << std::endl;
}
