/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:17:03 by revieira          #+#    #+#             */
/*   Updated: 2023/11/22 18:15:39 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << BLU "ScavTrap: Default Constructor Called" RESET << std::endl;
	this->_name = "";
	this->_hits = ScavTrap::defaultHits;
	this->_energyPoints = ScavTrap::defaultEnergyPoints;
	this->_attackDamage = ScavTrap::defaultAttackDamage;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << BLU "ScavTrap " << name << ": Constructor Called" RESET << std::endl;
	this->_name = name;
	this->_hits = ScavTrap::defaultHits;
	this->_energyPoints = ScavTrap::defaultEnergyPoints;
	this->_attackDamage = ScavTrap::defaultAttackDamage;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout << BLU "Copy Constructor Called" RESET << std::endl;
	if (this != &obj)
		*this = obj;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED "ScavTrap: Destructor Called" RESET << std::endl;
}

/* OPERATORS OVERLOADING */
ScavTrap	&ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << CYN "Copy Assignment Operator Called" RESET << std::endl;
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
	if (this->_hits == 0)
	{
		std::cout << YEL "ScavTrap " << this->_name << 
			" can't attack, has no hits points!" RESET << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << YEL "ScavTrap " << this->_name << 
			" can't attack, has no energy points!" RESET << std::endl;
		return ;
	}
	std::cout << GRN "ScavTrap " << this->_name << " attacks " << target << ", causing " <<
		this->_attackDamage << " points of damage!" RESET << std::endl;
	this->_energyPoints--;
}

void	ScavTrap::guardGate()
{
	std::cout << GRN "ScavTrap " << this->_name << 
		" is now in Gate keeper mode" RESET << std::endl;
}
