/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:39:34 by revieira          #+#    #+#             */
/*   Updated: 2023/12/13 15:11:32 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

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

AMateria	*Cure::clone() const
{
	AMateria *tmp = new Cure(*this);
	return (tmp);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;;
}
