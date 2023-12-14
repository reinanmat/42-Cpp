/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:39:34 by revieira          #+#    #+#             */
/*   Updated: 2023/12/14 15:09:57 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

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

Cure	&Cure::operator=(const Cure &obj)
{
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

AMateria	*Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;;
}
