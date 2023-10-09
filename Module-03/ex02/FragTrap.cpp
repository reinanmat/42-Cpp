/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:15:09 by revieira          #+#    #+#             */
/*   Updated: 2023/10/09 18:52:49 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
FragTrap::FragTrap()
{
	std::cout << "FragTrap: Default Constructor Called" << std::endl;
	this->setHits(FragTrap::defaultHits);
	this->setEnergyPoints(FragTrap::defaultEnergyPoints);
	this->setAttackDamage(FragTrap::defaultAttackDamage);
}

FragTrap::FragTrap(std::string name)
{
	std::cout << name << " FragTrap: Constructor Called" << std::endl;
	this->setName(name);
	this->setHits(FragTrap::defaultHits);
	this->setEnergyPoints(FragTrap::defaultEnergyPoints);
	this->setAttackDamage(FragTrap::defaultAttackDamage);
}

FragTrap::FragTrap(const FragTrap &obj)
{
	std::cout << "Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor Called" << std::endl;
}

/* OPERATORS OVERLOADING */
FragTrap	&FragTrap::operator=(FragTrap const &cpy)
{
	std::cout << "Copy Assignment Operator Called" << std::endl;
	if (this != &cpy)
	{
		this->setName(cpy.getName());
		this->setHits(cpy.getHits());
		this->setAttackDamage(cpy.getAttackDamage());
		this->setEnergyPoints(cpy.getEnergyPoints());
	}
	return (*this);
}

/* MEMBER FUNCTIONS */
void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " request a high five" << std::endl;
}
