/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:50:16 by revieira          #+#    #+#             */
/*   Updated: 2023/10/06 18:59:43 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap: Default Constructor Called" << std::endl;
	this->_hits = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: Destructor Called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << name << " ClapTrap: Constructor Called" << std::endl;
	this->_name = name;
	this->_hits = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &cpy)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &cpy)
		this->_name = cpy.getName();
	return (*this);
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

void	ClapTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << "ClapTrap " << this->getName() << " doens't have enough energy points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << 
		", causing " << this->getAttackDamage() << 
		" points of damage!" << std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->getName() << " Take Damage " << 
		amount << " points of damage!" << std::endl;
	if (this->getHits() - (int)amount <= 0)
		this->_hits = 0;
	else 
		this->_hits -= amount;
		
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << "ClapTrap " << this->getName() << " doens't have enough energy points" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->getName() << " be Repareired " << 
		amount << " points of lifes" << std::endl;
	this->_energyPoints--;
}
