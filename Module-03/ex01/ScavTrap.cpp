/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:17:03 by revieira          #+#    #+#             */
/*   Updated: 2023/10/10 17:31:58 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap: Default Constructor Called" << std::endl;
	this->_name = "";
	this->_hits = ScavTrap::defaultHits;
	this->_energyPoints = ScavTrap::defaultEnergyPoints;
	this->_attackDamage = ScavTrap::defaultAttackDamage;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << ": Constructor Called" << std::endl;
	this->_name = name;
	this->_hits = ScavTrap::defaultHits;
	this->_energyPoints = ScavTrap::defaultEnergyPoints;
	this->_attackDamage = ScavTrap::defaultAttackDamage;
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
ScavTrap	&ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hits = other._hits;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

/* MEMBER FUNCTIONS */
void	ScavTrap::attack(const std::string &target)
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
	this->_energyPoints--;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;
}
