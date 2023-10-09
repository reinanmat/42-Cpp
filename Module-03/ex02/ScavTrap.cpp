/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:17:03 by revieira          #+#    #+#             */
/*   Updated: 2023/10/09 15:02:07 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap: Default Constructor Called" << std::endl;
	this->setHits(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor Called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << name << " ScavTrap: Constructor Called" << std::endl;
	this->setName(name);
	this->setHits(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &cpy)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &cpy)
		this->setName(cpy.getName());
	return (*this);
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->getName() << "entered Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << "ScavTrap " << this->getName() << " doens't have enough energy points" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << 
		", causing " << this->getAttackDamage() << 
		" points of damage!" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap " << this->getName() << " Take Damage " << 
		amount << " points of damage!" << std::endl;
	if (this->getHits() - (int)amount <= 0)
		this->setHits(0);
	else 
		this->setHits(this->getHits() - amount);
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << "ScavTrap " << this->getName() << " doens't have enough energy points" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " be Repareired " << 
		amount << " points of lifes" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}
