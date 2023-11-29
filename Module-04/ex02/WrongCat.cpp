/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:54:21 by revieira          #+#    #+#             */
/*   Updated: 2023/11/29 15:46:42 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << BLU "WrongCat: Default Constructor Called" RESET << std::endl;
	this->type = "Cat";
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	std::cout << BLU "WrongCat: Copy Constructor Called" RESET << std::endl;
	if (this != &obj)
		*this = obj;
}

WrongCat::~WrongCat()
{
	std::cout << RED "WrongCat: Destructor Called" RESET << std::endl;
}

/* OPERATORS OVERLOADING */
WrongCat	&WrongCat::operator=(WrongCat const &other)
{
	std::cout << CYN "WrongCat: Copy Assignment Operator Called" RESET << std::endl;
	if (this != &other)
		this->type = type;
	return (*this);
}

/* MEMBER FUNCTIONS */
void  WrongCat::makeSound(void) const
{
	std::cout << GRN "The WrongCat say: Meow!" RESET << std::endl;
}
