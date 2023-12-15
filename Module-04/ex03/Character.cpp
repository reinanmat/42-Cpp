/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:42:48 by revieira          #+#    #+#             */
/*   Updated: 2023/12/15 14:57:59 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

static void	initInventory(AMateria **inventory);
static void copyInventory(AMateria **dest, AMateria **src);
static void	deleteInventory(AMateria **inventory);

/* CONSTRUCTORS AND DESTRUCTOR */
Character::Character() : ICharacter(), _currSize(0), _name("")
{
	initInventory(this->_inventory);
}

Character::Character(std::string name) : ICharacter(), _currSize(0), _name(name)
{
	initInventory(this->_inventory);
}

Character::Character(const Character &obj) : ICharacter(), _currSize(0), _name("")
{
	initInventory(this->_inventory);
	if (this != &obj)
		*this = obj;
}

Character::~Character()
{
	deleteInventory(this->_inventory);
}

/* OPERATORS OVERLOADING */
Character	&Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_currSize = other._currSize;
		deleteInventory(this->_inventory);
		copyInventory(this->_inventory, const_cast<AMateria **>(other._inventory));
	}
	return (*this);
}

/* GETTERS */
std::string const &Character::getName() const
{
	return (this->_name);
}

/* MEMBER FUNCTIONS */
void Character::equip(AMateria* m)
{
	if (!m)
		std::cout << RED "Invalid materia" RESET << std::endl;
	else if (this->_currSize + 1 > MAX_SLOTS)
	{
		std::cout << YEL "Inventory full" RESET << std::endl;
		delete m;
	}
	else
	{
		this->_currSize++;
		for (int i = 0; i < 4; i++)
		{
			if (!this->_inventory[i])
			{
				this->_inventory[i] = m;
				break ;
			}
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= MAX_SLOTS)
		std::cout << "Invalid index" << std::endl;
	else if (this->_inventory[idx] == NULL)
		std::cout << "Nothing to be unequipped" << std::endl;
	else
	{
		delete this->_inventory[idx];
		this->_inventory[idx] = NULL;
		this->_currSize--;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= MAX_SLOTS)
		std::cout << RED "Invalid index" RESET << std::endl;
	else if (!this->_inventory[idx])
		std::cout << YEL "nothing to be used" RESET << std::endl;
	else
		this->_inventory[idx]->use(target);
}

/* UTILS */
static void	initInventory(AMateria **inventory)
{
	std::memset(inventory, 0, sizeof(AMateria *) * MAX_SLOTS);
}

static void copyInventory(AMateria **dest, AMateria **src)
{
	for (int i = 0; i < MAX_SLOTS; i++)
		if (src[i])
			dest[i] = src[i]->clone();
}

static void	deleteInventory(AMateria **inventory)
{
	for (int i = 0; i < MAX_SLOTS; i++)
		if (inventory[i])
			delete inventory[i];
	std::memset(inventory, 0, sizeof(AMateria *) * MAX_SLOTS);
}
