/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:54:21 by revieira          #+#    #+#             */
/*   Updated: 2023/10/16 15:12:49 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat: Default Constructor Called" << std::endl;
	this->type = "Cat";
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	std::cout << "WrongCat: Copy Constructor Called" << std::endl;
	if (this != &obj)
		*this = obj;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor Called" << std::endl;
}

/* OPERATORS OVERLOADING */
WrongCat	&WrongCat::operator=(WrongCat const &other)
{
	std::cout << "WrongCat: Copy Assignment Operator Called" << std::endl;
	if (this != &other)
		this->type = type;
	return (*this);
}

/* MEMBER FUNCTIONS */
void  WrongCat::makeSound(void) const
{
	std::cout << "The WrongCat say: Meow!" << std::endl;
}
