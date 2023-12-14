/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:12:42 by revieira          #+#    #+#             */
/*   Updated: 2023/12/14 15:06:52 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

static	void deleteMaterialsLearned(AMateria **array)
{
	for (int i = 0; i < 4; i++)
	{
		if (array[i])
		{
			delete array[i];
			array[i] = NULL;
		}
	}
}

MateriaSource::MateriaSource() : _size(0)
{
	std::memset(this->_types, 0, sizeof(MateriaSource *) * 4);
}

MateriaSource::MateriaSource(const MateriaSource &obj) : _size(0)
{
	if (this != &obj)
		*this = obj;
}

MateriaSource::~MateriaSource()
{
	deleteMaterialsLearned(this->_types);
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		this->_size = other._size;
		deleteMaterialsLearned(this->_types);
		for (int i = 0; i < 4; i++)
			if (other._types[i])
				this->_types[i] = other._types[i];
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (this->_size + 1 >  4)
		return ;
	this->_types[this->_size] = m;
	this->_size++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->_size; i++)
		if (this->_types[i] && this->_types[i]->getType() == type)
			return (this->_types[i]->clone());
	return (NULL);
}
