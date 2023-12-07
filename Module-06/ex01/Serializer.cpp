/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:11:57 by revieira          #+#    #+#             */
/*   Updated: 2023/12/07 15:07:00 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Serializer::Serializer()
{

}

Serializer::Serializer(const Serializer &obj)
{
	(void)obj;
}

Serializer::~Serializer()
{

}

/* OPERATORS OVERLOADING */
Serializer	&Serializer::operator=(const Serializer &other)
{
	(void)other;
	return (*this);
}

/* MEMBER FUNCTIONS */
uintptr_t	Serializer::serializer(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
