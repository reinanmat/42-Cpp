/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:50:16 by revieira          #+#    #+#             */
/*   Updated: 2023/11/22 17:51:12 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
ClapTrap::ClapTrap()
{
	std::cout << BLU "ClapTrap: Default Constructor Called" RESET << std::endl;
	this->_name = "";
	this->_hits = ClapTrap::defaultHits;
	this->_energyPoints = ClapTrap::defaultEnergyPoints;
	this->_attackDamage = ClapTrap::defaultAttackDamage;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << BLU "ClapTrap " << name << ": Constructor Called" RESET << std::endl;
	this->_name = name;
	this->_hits = ClapTrap::defaultHits;
	this->_energyPoints = ClapTrap::defaultEnergyPoints;
	this->_attackDamage = ClapTrap::defaultAttackDamage;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << BLU "ClapTrap: Copy Constructor Called" RESET << std::endl;
	if (this != &obj)
		*this = obj;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED "ClapTrap: Destructor Called" RESET << std::endl;
}

/* OPERATORS OVERLOADING */
ClapTrap	&ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << CYN "ClapTrap: Copy Assignment Operator Called" RESET << std::endl;
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
	if (this->_hits == 0)
	{
		std::cout << YEL "ClapTrap " << this->_name << 
			" can't attack, has no hits points!" RESET << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << YEL "ClapTrap " << this->_name << 
			" can't attack, has no energy points!" RESET << std::endl;
		return ;
	}
	std::cout << GRN "ClapTrap " << this->_name << " attacks " << target << ", causing " <<
		this->_attackDamage << " points of damage!" RESET << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hits == 0 || this->_hits - (int)amount <= 0)
	{
		std::cout << RED << this->_name << " take damage " << amount
			<< " points of damage and was defeated!" RESET << std::endl;
		this->_hits = 0;
	}
	else
	{
		std::cout << YEL << this->_name << " take damage "
			<< amount << " points of damage!" RESET << std::endl;
		this->_hits -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << YEL << this->_name 
			<< " cannot be repaired, has no energy points!" RESET << std::endl;
		return ;
	}
	else
	{
		std::cout << GRN << this->_name << " was repaired and healed "
			<< amount << " hits points!" RESET << std::endl;
		this->_hits += amount;
		this->_energyPoints--;
	}
}

void	ClapTrap::printStatus(void) const
{
	std::cout << CYN "====================STATUS====================" << std::endl;
	std::cout << "\t\tNAME:\t" << this->_name << std::endl;
	std::cout << "\t\tHP:\t" << this->_hits << std::endl;
	std::cout << "\t\tATK:\t" << this->_attackDamage << std::endl;
	std::cout << "\t\tEP:\t" << this->_energyPoints << RESET << std::endl;
}
