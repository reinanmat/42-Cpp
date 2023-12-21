/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:58:55 by revieira          #+#    #+#             */
/*   Updated: 2023/12/21 15:10:58 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Data::Data() : _value(0) {}

Data::Data(int value) : _value(value) {}

Data::Data(const Data &obj)
{
	if (this != &obj)
		*this = obj;
}

Data::~Data() {}

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
