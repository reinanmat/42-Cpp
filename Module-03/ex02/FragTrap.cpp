/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:15:09 by revieira          #+#    #+#             */
/*   Updated: 2023/10/10 18:06:09 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap: Default Constructor Called" << std::endl;
	this->_name = "";
	this->_hits = FragTrap::defaultHits;
	this->_energyPoints = FragTrap::defaultEnergyPoints;
	this->_attackDamage = FragTrap::defaultAttackDamage;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << name << " FragTrap: Constructor Called" << std::endl;
	this->_name = name;
	this->_hits = FragTrap::defaultHits;
	this->_energyPoints = FragTrap::defaultEnergyPoints;
	this->_attackDamage = FragTrap::defaultAttackDamage;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor Called" << std::endl;
}

/* OPERATORS OVERLOADING */
FragTrap	&FragTrap::operator=(FragTrap const &other)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHits(other.getHits());
		this->setAttackDamage(other.getAttackDamage());
		this->setEnergyPoints(other.getEnergyPoints());
	}
	return (*this);
}

/* MEMBER FUNCTIONS */
void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " request a high five" << std::endl;
}
