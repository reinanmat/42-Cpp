/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:42:48 by revieira          #+#    #+#             */
/*   Updated: 2023/12/14 14:54:20 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <cstring>

Character::Character() : ICharacter(), _size(0), _name("")
{
	std::memset(this->_invetory, 0, sizeof(AMateria *) * 4);
}

Character::Character(std::string name) : ICharacter(), _size(0), _name(name)
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
		this->_size = other->_size;
		std::memset(this->_invetory, 0, sizeof(AMateria *) * 4);
		for (int i = 0; i < 4; i++)
			if (other->_invetory[i])
				this->_invetory[i] = other->_invetory[i];
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (this->_size + 1 > 4)
		return ;
	this->_size++;
	for (int i = 0; i < 4; i++)
	{
		if (!this->_invetory[i])
		{
			this->_invetory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	this->_invetory[idx] = NULL;
	this->_size--;
}

void Character::use(int idx, ICharacter& target)
{
	if (!this->_invetory[idx])
		std::cout << "Error" << std::endl;
	this->_invetory[idx]->use(target);
}
