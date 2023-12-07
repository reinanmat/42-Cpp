/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:58:55 by revieira          #+#    #+#             */
/*   Updated: 2023/12/07 15:03:09 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Data::Data() : _value(0)
{
	return ;
}

Data::Data(int value) : _value(value)
{
	return ;
}

Data::Data(const Data &obj)
{
	if (this != &obj)
		*this = obj;
}

Data::~Data()
{
	return ;
}

/* OPERATORS OVERLOADING */
Data	&Data::operator=(const Data &other)
{
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

/* GETTERS AND SETTERS */
int	Data::getValue()
{
	return (this->_value);
}

void	Data::setValue(int value)
{
	this->_value = value;
}
