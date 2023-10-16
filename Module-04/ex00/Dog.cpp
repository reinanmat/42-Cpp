/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:51:02 by revieira          #+#    #+#             */
/*   Updated: 2023/10/16 15:12:36 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Dog::Dog() : Animal()
{
	std::cout << "Dog: Default Constructor Called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << "Dog: Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor Called" << std::endl;
}

/* OPERATORS OVERLOADING */
Dog	&Dog::operator=(Dog const &other)
{
	std::cout << "Dog: Copy Assignment Operator Called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

/* MEMBER FUNCTIONS */
void  Dog::makeSound(void) const
{
	std::cout << "The dog say: Auu!" << std::endl;
}
