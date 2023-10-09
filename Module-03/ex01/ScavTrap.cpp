/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:17:03 by revieira          #+#    #+#             */
/*   Updated: 2023/10/09 18:29:46 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap: Default Constructor Called" << std::endl;
	this->setHits(ScavTrap::defaultHits);
	this->setEnergyPoints(ScavTrap::defaultEnergyPoints);
	this->setAttackDamage(ScavTrap::defaultAttackDamage);
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap " << name << ": Constructor Called" << std::endl;
	this->setName(name);
	this->setHits(ScavTrap::defaultHits);
	this->setEnergyPoints(ScavTrap::defaultEnergyPoints);
	this->setAttackDamage(ScavTrap::defaultAttackDamage);
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor Called" << std::endl;
}

/* OPERATORS OVERLOADING */
ScavTrap	&ScavTrap::operator=(ScavTrap const &cpy)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &cpy)
	{
		this->setName(cpy.getName());
		this->setHits(cpy.getHits());
		this->setAttackDamage(cpy.getAttackDamage());
		this->setEnergyPoints(cpy.getEnergyPoints());
	}
	return (*this);
}

/* MEMBER FUNCTIONS */
void	ScavTrap::attack(const std::string& target)
{
	if (this->getHits() == 0)
	{
		std::cout << "ScavTrap " << this->getName() 
			<< " can't attack, has no hits points!" << std::endl;
		return ;
	}
	if (this->getEnergyPoints() == 0)
	{
		std::cout << "ScavTrap " << this->getName() 
			<< " can't attack, has no energy points!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << 
		", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
}
