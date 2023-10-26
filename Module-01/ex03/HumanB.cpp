/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:14:19 by revieira          #+#    #+#             */
/*   Updated: 2023/10/26 17:14:13 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
HumanB::HumanB() {}

HumanB::~HumanB() {}

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}

/* MEMBER FUNCTIONS */
void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << this->_name;
	if (!this->_weapon)
		 std::cout << " is disarmed" << std::endl;
	else
		std::cout << " attacks with their " + this->_weapon->getType() << std::endl;
}
