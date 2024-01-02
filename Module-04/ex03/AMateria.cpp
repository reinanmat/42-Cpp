/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:26:06 by revieira          #+#    #+#             */
/*   Updated: 2023/12/19 14:59:30 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp" 

/* CONSTRUCTORS AND DESTRUCTOR */
AMateria::AMateria() : _type("") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &obj)
{
	if (this != &obj)
		*this = obj;
}

AMateria::~AMateria() {}

/* OPERATORS OVERLOADING */
AMateria	&AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

/* GETTERS */
std::string const &AMateria::getType() const
{
	return (this->_type);
}

/* MEMBER FUNCTIONS */
void AMateria::use(ICharacter& target)
{
	std::cout << "Default use: " << target.getName() << std::endl;
}
