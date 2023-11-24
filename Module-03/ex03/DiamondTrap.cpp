/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:02:46 by revieira          #+#    #+#             */
/*   Updated: 2023/11/24 17:05:28 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << BLU "DiamondTrap: Default Constructor Called" RESET << std::endl;
	this->_name = "";
	this->_hits = FragTrap::defaultHits;
	this->_energyPoints = ScavTrap::defaultEnergyPoints;
	this->_attackDamage = FragTrap::defaultAttackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap const &obj) : ClapTrap(obj), FragTrap(obj), ScavTrap(obj)
{
	std::cout << BLU "DiamonTrap: Copy Constructor Called" RESET << std::endl;
	if (this != &obj)
		*this = obj;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"),
FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
	std::cout << BLU "DiamondTrap " << name << ": Constructor Called" RESET << std::endl;
	this->_name = name;
	this->_hits = FragTrap::defaultHits;
	this->_energyPoints = ScavTrap::defaultEnergyPoints;
	this->_attackDamage = FragTrap::defaultAttackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED "DiamondTrap: Destructor Called" RESET << std::endl;
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
	std::cout << CYN "Copy Assignment Operator Called" RESET << std::endl;
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
	std::cout << MAG "Name: " << this->_name << ", ClapTrap name: "
		<< ClapTrap::_name << RESET << std::endl;
}

void	DiamondTrap::printStatus(void) const
{
	std::cout << CYN "====================STATUS====================" << std::endl;
	std::cout << "\t\tC_NAME:\t" << ClapTrap::_name << std::endl;
	std::cout << "\t\tNAME:\t" << this->_name << std::endl;
	std::cout << "\t\tATK:\t" << this->_attackDamage << std::endl;
	std::cout << "\t\tHP:\t" << this->_hits << std::endl;
	std::cout << "\t\tEP:\t" << this->_energyPoints << RESET << std::endl;
}
