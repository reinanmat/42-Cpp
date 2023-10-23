/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:14:19 by revieira          #+#    #+#             */
/*   Updated: 2023/10/23 14:20:54 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
HumanA::HumanA() {}

HumanA::~HumanA() {}

HumanA::HumanA(std::string name, Weapon& weapon)
{
	this->_name = name;
	this->_weapon = &weapon;
}

/* MEMBER FUNCTIONS */
void	HumanA::attack(void)
{
	std::cout << this->_name;
	if (!this->_weapon)
		 std::cout << " is disarmed" << std::endl;
	else
		std::cout <<" attacks with their " + this->_weapon->getType() << std::endl;
}
