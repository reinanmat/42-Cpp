/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:42:48 by revieira          #+#    #+#             */
/*   Updated: 2023/12/13 15:08:18 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : ICharacter(), _name("")
{
	for (int i = 0; i < 4; i++)
		this->_invetory[i] = NULL;
}

Character::Character(std::string name) : ICharacter(), _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_invetory[i] = NULL;
}

Character::Character(const Character &obj) : ICharacter()
{
	if (this != &obj)
		*this = obj;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->_invetory[i])
			delete this->_invetory[i];
}

Character	&Character::operator=(const Character *other)
{
	if (this != other)
	{
		this->_name = other->_name;
		//copy invetory;
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	this->_invetory[0] = m;
}

void Character::unequip(int idx)
{
	this->_invetory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	this->_invetory[idx]->use(target);
}