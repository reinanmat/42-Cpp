/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:17:03 by revieira          #+#    #+#             */
/*   Updated: 2023/11/09 19:25:43 by revieira         ###   ########.fr       */
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

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
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
	std::cout << "ScavTrap " << this->_name;
	if (this->_hits == 0)
	{
		std::cout << " can't attack, has no hits points!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << " can't attack, has no energy points!" << std::endl;
		return ;
	}
	std::cout << " attacks " << target << ", causing " << 
		this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}
