/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:16:48 by revieira          #+#    #+#             */
/*   Updated: 2023/10/06 16:35:09 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	/* std::cout << "Default constructor called" << std::endl; */
	this->_fixedPoint = 0;
}

Fixed::Fixed(Fixed const &obj)
{
	/* std::cout << "Copy constructor called" << std::endl; */
	if (this != &obj)
		*this = obj;
}

Fixed::~Fixed()
{
	/* std::cout << "Destructor called" << std::endl; */
}

Fixed::Fixed(const int &num)
{
	/* std::cout << "Int constructor called" << std::endl; */
	this->_fixedPoint = num * (1 << this->_fractionalBits);
}

Fixed::Fixed(const float &num)
{
	/* std::cout << "Float constructor called" << std::endl; */
	this->_fixedPoint = (int)roundf(num * (1 << this->_fractionalBits));
}

int		Fixed::getRawBits(void) const
{
	/* std::cout << "getRawBits member function called" << std::endl; */
	return this->_fixedPoint;
}

void	Fixed::setRawBits(int const raw)
{
	/* std::cout << "setRawBits member function called" << std::endl; */
	this->_fixedPoint = raw;
}

Fixed	&Fixed::operator=(const Fixed &cpy)
{
	/* std::cout << "Copy assignment operator called" << std::endl; */
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
	return (out);
}

Fixed	Fixed::operator+(const Fixed &x) const
{
	Fixed result((this->toFloat() + x.toFloat()));
	return (result);
}

Fixed	Fixed::operator-(const Fixed &x) const
{
	Fixed result((this->toFloat() - x.toFloat()));
	return (result);
}

Fixed	Fixed::operator*(const Fixed &x) const
{
	Fixed result((this->toFloat() * x.toFloat()));
	return (result);
}

Fixed	Fixed::operator/(const Fixed &x) const
{
	Fixed result(this->toFloat() / x.toFloat());
	return (result);
}

bool	Fixed::operator==(const Fixed &cmp) const
{
	return (this->getRawBits() == cmp.getRawBits());
}

bool	Fixed::operator!=(const Fixed &cmp) const
{
	return (this->getRawBits() != cmp.getRawBits());
}

bool	Fixed::operator<(const Fixed &cmp) const
{
	return (this->getRawBits() < cmp.getRawBits());
}

bool	Fixed::operator>(const Fixed &cmp) const
{
	return (this->getRawBits() > cmp.getRawBits());
}

bool	Fixed::operator>=(const Fixed &cmp) const
{
	return (*this > cmp || *this == cmp);
}

bool	Fixed::operator<=(const Fixed &cmp) const
{
	return (*this < cmp || *this == cmp);
}

Fixed	&Fixed::operator++()
{
	this->_fixedPoint++;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	this->_fixedPoint--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	this->_fixedPoint++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	this->_fixedPoint--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a > b ? b : a);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	Fixed	tmp_a(a);
	Fixed	tmp_b(b);
	
	return (Fixed::min(tmp_a, tmp_b));
}

Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	Fixed	tmp_a(a);
	Fixed	tmp_b(b);
	
	return (Fixed::max(tmp_a, tmp_b));
}
