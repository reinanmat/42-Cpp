/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:54:20 by revieira          #+#    #+#             */
/*   Updated: 2023/10/20 18:45:55 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Zombie::Zombie() {}

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": is dead" << std::endl;
}

/* OPERATORS OVERLOADING */
Zombie	&Zombie::operator=(const Zombie &other)
{
	this->_name = other._name;
	return *this;
}

/* GETTERS AND SETTERS*/
std::string	Zombie::getName(void)
{
	return this->_name;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

/* MEMBER FUNCTIONS */
void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
