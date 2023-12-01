/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:29:26 by revieira          #+#    #+#             */
/*   Updated: 2023/12/01 15:32:09 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	this->_type = "ice";
}

Ice::Ice(const Ice &obj) : AMateria("ice")
{
	if (this != &obj)
		*this = obj;
}

Ice::~Ice()
{
	return ;
}

Ice	&Ice::operator=(const Ice &obj)
{
	if (this != &obj)
		this->_type = obj._type;
	return (*this);
}

AMateria	*Ice::clone()
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;;
}
