/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:16:48 by revieira          #+#    #+#             */
/*   Updated: 2023/10/06 14:11:35 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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

Fixed	&Fixed::operator=(const Fixed &cpy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &cpy)
		this->_fixedPoint = cpy.getRawBits();
	return (*this);
}

int	Fixed::toInt(void) const
{
	return (this->_fixedPoint / (1 << this->_fractionalBits));
}

float	Fixed::toFloat(void) const
{
	return (this->_fixedPoint / (float)(1 << this->_fractionalBits));
}

std::ostream	&operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return out;
}
