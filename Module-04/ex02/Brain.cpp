/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:45:32 by revieira          #+#    #+#             */
/*   Updated: 2023/11/29 16:58:45 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Brain::Brain()
{
	std::cout << BLU "Brain: Default Constructor Called" RESET << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "No idea";
}

Brain::Brain(const Brain &obj)
{
	std::cout << BLU "Brain: Copy Constructor Called" RESET << std::endl;
	if (this != &obj)
		*this = obj;
}

Brain::~Brain()
{
	std::cout << RED "Brain: Destructor Called" RESET << std::endl;
}

/* OPERATORS OVERLOADING */
Brain	&Brain::operator=(const Brain &other)
{
	std::cout << CYN "Brain: Copy Assignment Operator Called" RESET << std::endl;
	if (this != &other)
		std::copy(other._ideas, other._ideas + 100, this->_ideas);
	return (*this);
}

/* GETTERS AND SETTERS */
std::string	Brain::getIdea(size_t index) const
{
	if (index >= 100)
	{
		std::cout << "index out of range!" << std::endl;
		return("");
	}
	return (this->_ideas[index]);
}

void	Brain::setIdea(size_t index, std::string idea)
{
	if (index >= 100)
	{
		std::cout << "index out of range!" << std::endl;
		return ;
	}
	this->_ideas[index] = idea;
}
