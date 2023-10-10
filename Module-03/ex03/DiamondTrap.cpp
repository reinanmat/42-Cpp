/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:02:46 by revieira          #+#    #+#             */
/*   Updated: 2023/10/10 16:46:44 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap: Default Constructor Called" << std::endl;
	this->_name = "";
	this->_hits = FragTrap::defaultHits;
	this->_energyPoints = ScavTrap::defaultEnergyPoints;
	this->_attackDamage = FragTrap::defaultAttackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap const &obj)
{
	std::cout << "DiamonTrap: Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap " << name << ": Constructor Called" << std::endl;
	this->_name = name;
	this->_hits = FragTrap::defaultHits;
	this->_energyPoints = ScavTrap::defaultEnergyPoints;
	this->_attackDamage = FragTrap::defaultAttackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Destructor Called" << std::endl;
}

/* GETTERS AND SETTERS */
std::string	DiamondTrap::getName(void) const
{
	return (this->_name);
}

std::string DiamondTrap::getClapName(void) const
{
	return (ClapTrap::_name);
}

void	DiamondTrap::setName(std::string name)
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
}

/* OPERATORS OVERLOADING */
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &cpy)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &cpy)
	{
		ClapTrap::_name = cpy._name + "_clap_name";
		this->_name = cpy._name;
		this->_hits = cpy._hits;
		this->_attackDamage = cpy._attackDamage;
		this->_energyPoints = cpy._energyPoints;
	}
	return (*this);
}

/* MEMBER FUNCTIONS */
void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
