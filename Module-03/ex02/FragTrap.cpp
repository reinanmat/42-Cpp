/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:15:09 by revieira          #+#    #+#             */
/*   Updated: 2023/10/09 15:18:51 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap: Default Constructor Called" << std::endl;
	this->setHits(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor Called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << name << " FragTrap: Constructor Called" << std::endl;
	this->setName(name);
	this->setHits(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

FragTrap	&FragTrap::operator=(FragTrap const &cpy)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &cpy)
		this->setName(cpy.getName());
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << "FragTrap " << this->getName() << " doens't have enough energy points" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->getName() << " attacks " << target << 
		", causing " << this->getAttackDamage() << 
		" points of damage!" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap " << this->getName() << " Take Damage " << 
		amount << " points of damage!" << std::endl;
	if (this->getHits() - (int)amount <= 0)
		this->setHits(0);
	else 
		this->setHits(this->getHits() - amount);
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << "FragTrap " << this->getName() << " doens't have enough energy points" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->getName() << " be Repareired " << 
		amount << " points of lifes" << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}
