/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:51:02 by revieira          #+#    #+#             */
/*   Updated: 2023/11/29 18:10:57 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Dog::Dog() : Animal()
{
	std::cout << BLU "Dog: Default Constructor Called" RESET << std::endl;
	this->type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << BLU "Dog: Copy Constructor Called" RESET << std::endl;
	if (this != &obj)
		*this = obj;
}

Dog::~Dog()
{
	std::cout << RED "Dog: Destructor Called" RESET << std::endl;
	delete this->_brain;
}

/* OPERATORS OVERLOADING */
Dog	&Dog::operator=(Dog const &other)
{
	std::cout << CYN "Dog: Copy Assignment Operator Called" RESET << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		*(this->_brain) = *(other._brain);
	}
	return (*this);
}

/* GETTERS AND SETTERS */
std::string	Dog::getIdeaOfBrain(size_t index) const
{
	return (this->_brain->getIdea(index));
}

void	Dog::setIdeaOfBrain(size_t index, std::string idea)
{
	this->_brain->setIdea(index, idea);
}

/* MEMBER FUNCTIONS */
void  Dog::makeSound(void) const
{
	std::cout << GRN "The dog say: Auu!" RESET << std::endl;
}
