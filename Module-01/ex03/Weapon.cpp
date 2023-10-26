/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:40:01 by revieira          #+#    #+#             */
/*   Updated: 2023/10/26 17:06:58 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Weapon::Weapon() {}

Weapon::~Weapon() {}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

/* GETTERS AND SETTERS */
void	Weapon::setType(std::string type)
{
	this->type = type;
}

const std::string &Weapon::getType()
{
	return this->type;
}
