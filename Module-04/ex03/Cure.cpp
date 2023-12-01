/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:39:34 by revieira          #+#    #+#             */
/*   Updated: 2023/12/01 15:31:21 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure() : AMateria("ice")
{
	this->_type = "ice";
}

Cure::Cure(const Cure &obj) : AMateria("ice")
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

AMateria	*Cure::clone()
{
	AMateria *tmp = new (Cure);
	return (tmp);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;;
}
