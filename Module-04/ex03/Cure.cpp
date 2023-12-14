/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:39:34 by revieira          #+#    #+#             */
/*   Updated: 2023/12/14 18:38:17 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Cure::Cure() : AMateria("cure")
{
	this->_type = "cure";
}

Cure::Cure(const Cure &obj) : AMateria("cure")
{
	if (this != &obj)
		*this = obj;
}

Cure::~Cure()
{
	return ;
}

/* OPERATORS OVERLOADING */
Cure	&Cure::operator=(const Cure &obj)
{
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

/* MEMBER FUNCTIONS */
AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;;
}
