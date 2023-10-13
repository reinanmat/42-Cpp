/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:16:48 by revieira          #+#    #+#             */
/*   Updated: 2023/10/13 17:53:35 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPoint = 0;
}

Fixed::Fixed(Fixed const &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &obj)
		*this = obj;
}

Fixed::Fixed(const int &num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = num * (1 << this->_fractionalBits);
}

Fixed::Fixed(const float &num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = (int)roundf(num * (1 << this->_fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* OPERATORS OVERLOADING */
Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPoint = other.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return out;
}

/* GETTERS AND SETTERS */
int		Fixed::getRawBits(void) const
{
	/* std::cout << "getRawBits member function called" << std::endl; */
	return this->_fixedPoint;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPoint = raw;
}

/* MEMBER FUNCTIONS */
int	Fixed::toInt(void) const
{
	return (this->_fixedPoint / (1 << this->_fractionalBits));
}

float	Fixed::toFloat(void) const
{
	return (this->_fixedPoint / (float)(1 << this->_fractionalBits));
}
