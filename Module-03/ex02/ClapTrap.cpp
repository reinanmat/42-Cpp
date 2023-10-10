/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:50:16 by revieira          #+#    #+#             */
/*   Updated: 2023/10/10 17:57:10 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap: Default Constructor Called" << std::endl;
	this->_name = "";
	this->_hits = ClapTrap::defaultHits;
	this->_energyPoints = ClapTrap::defaultEnergyPoints;
	this->_attackDamage = ClapTrap::defaultAttackDamage;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap " << name << ": Constructor Called" << std::endl;
	this->_name = name;
	this->_hits = ClapTrap::defaultHits;
	this->_energyPoints = ClapTrap::defaultEnergyPoints;
	this->_attackDamage = ClapTrap::defaultAttackDamage;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "ClapTrap: Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor Called" << std::endl;
}

/* OPERATORS OVERLOADING */
ClapTrap	&ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "ClapTrap: Copy Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hits = other._hits;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

/* GETTERS AND SETTERS */
std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int	ClapTrap::getHits(void) const
{
	return (this->_hits);
}

int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHits(int hits)
{
	this->_hits = hits;
}

void	ClapTrap::setEnergyPoints(int energyPoints)
{
	this->_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(int attackDamage)
{
	this->_attackDamage = attackDamage;
}

/* MEMBER FUNCTIONS */
void	ClapTrap::attack(const std::string &target)
{
	if (this->getHits() == 0)
	{
		std::cout << "ClapTrap " << this->getName()
			<< " can't attack, has no hits points!" << std::endl;
		return ;
	}
	if (this->getEnergyPoints() == 0)
	{
		std::cout << "ClapTrap " << this->getName()
			<< " can't attack, has no energy points!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " attacks " << target <<
		", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->getName() << " take damage " <<
		amount << " points of damage!";
	if (this->getHits() - (int)amount <= 0) {
		std::cout << " and was defeated!" << std::endl;
		this->_hits = 0;
	} else {
		std::cout << std::endl;
		this->_hits -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << this->getName()
			<< " cannot be repaired, has no energy points!" << std::endl;
		return ;
	}
	std::cout << this->getName() << " was repaired and healed " <<
		amount << " hits points!" << std::endl;
	this->_hits += amount;
	this->_energyPoints--;
}

void	ClapTrap::printStatus(void) const
{
	std::cout << "====================STATUS====================" << std::endl;
	std::cout << "NAME:\t" << this->getName() << std::endl;
	std::cout << "HP:\t" << this->getHits() << std::endl;
	std::cout << "ATK:\t" << this->getAttackDamage() << std::endl;
	std::cout << "EP:\t" << this->getEnergyPoints() << std::endl;
}
