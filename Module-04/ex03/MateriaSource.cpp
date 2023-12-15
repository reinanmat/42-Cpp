/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:12:42 by revieira          #+#    #+#             */
/*   Updated: 2023/12/15 14:55:54 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

static void	initMaterials(AMateria **materials);
static void	copyMaterials(AMateria **dest, AMateria **src);
static void	deleteMaterials(AMateria **materials);

/* CONSTRUCTORS AND DESTRUCTOR */
MateriaSource::MateriaSource() : _currSize(0)
{
	initMaterials(this->_materials);
}

MateriaSource::MateriaSource(const MateriaSource &obj) : _currSize(0)
{
	initMaterials(this->_materials);
	if (this != &obj)
		*this = obj;
}

MateriaSource::~MateriaSource()
{
	deleteMaterials(this->_materials);
}

/* OPERATORS OVERLOADING */
MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		this->_currSize = other._currSize;
		deleteMaterials(this->_materials);
		copyMaterials(this->_materials, const_cast<AMateria **>(other._materials));
	}
	return (*this);
}

/* MEMBER FUNCTIONS */
void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		std::cout << RED "Invalid materia" RESET << std::endl;
	else if (this->_currSize + 1 > MAX_MATERIALS)
	{
		std::cout << YEL "Maximum number of materials learned" RESET << std::endl;
		delete m;
	}
	else
	{
		this->_materials[this->_currSize] = m;
		this->_currSize++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->_currSize; i++)
		if (this->_materials[i] && this->_materials[i]->getType() == type)
			return (this->_materials[i]->clone());
	return (NULL);
}

/* UTILS */
static void	initMaterials(AMateria **materials)
{
	std::memset(materials, 0, sizeof(MateriaSource *) * MAX_MATERIALS);
}

static void	copyMaterials(AMateria **dest, AMateria **src)
{
	for (int i = 0; i < 4; i++)
		if (src[i])
			dest[i] = src[i]->clone();
}

static	void deleteMaterials(AMateria **materials)
{
	for (int i = 0; i < 4; i++)
		if (materials[i])
			delete materials[i];
	std::memset(materials, 0, sizeof(MateriaSource *) * MAX_MATERIALS);
}
