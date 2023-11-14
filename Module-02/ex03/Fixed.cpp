/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:16:48 by revieira          #+#    #+#             */
/*   Updated: 2023/11/14 16:28:52 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Fixed::Fixed() : _fixedPoint(0)
{
	#ifdef DEBUG
		std::cout << "Fixed: Default constructor called" << std::endl;
	#endif
}

Fixed::Fixed(const Fixed &obj)
{
	#ifdef DEBUG
		std::cout << "Fixed: Copy constructor called" << std::endl;
	#endif
	if (this != &obj)
		*this = obj;
}

Fixed::Fixed(const int &num)
{
	#ifdef DEBUG
		std::cout << "Fixed: Int constructor called" << std::endl;
	#endif
	this->_fixedPoint = num * (1 << this->_fractionalBits);
}

Fixed::Fixed(const float &num)
{
	#ifdef DEBUG
		std::cout << "Fixed: Float constructor called" << std::endl;
	#endif
	this->_fixedPoint = (int)roundf(num * (1 << this->_fractionalBits));
}

Fixed::~Fixed()
{
	#ifdef DEBUG
		std::cout << "Fixed: Destructor called" << std::endl;
	#endif
}

/* GETTERS AND SETTERS */
int	Fixed::getRawBits(void) const
{
	#ifdef DEBUG
		std::cout << "Fixed: getRawBits member function called" << std::endl;
	#endif
	return this->_fixedPoint;
}

void	Fixed::setRawBits(int const raw)
{
	#ifdef DEBUG
		std::cout << "Fixed: setRawBits member function called" << std::endl;
	#endif
	this->_fixedPoint = raw;
}

/* MEMBER FUNCTIONS */
int	Fixed::toInt(void) const
{
	#ifdef DEBUG
		std::cout << "Fixed: toInt member function called" << std::endl;
	#endif
	return (this->_fixedPoint / (1 << this->_fractionalBits));
}

float	Fixed::toFloat(void) const
{
	#ifdef DEBUG
		std::cout << "Fixed: toFloat member function called" << std::endl;
	#endif
	return (this->_fixedPoint / (float)(1 << this->_fractionalBits));
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	#ifdef DEBUG
		std::cout << "Fixed: min member function called" << std::endl;
	#endif
	return (a <= b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	#ifdef DEBUG
		std::cout << "Fixed: max member function called" << std::endl;
	#endif
	return (a >= b ? a : b);
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

/* OPERATORS OVERLOADING */
Fixed	&Fixed::operator=(const Fixed &cpy)
{
	#ifdef DEBUG
		std::cout << "Fixed: Copy assignment operator called" << std::endl;
	#endif
	if (this != &cpy)
		this->_fixedPoint = cpy.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &obj)
{
	#ifdef DEBUG
		std::cout << "Fixed: Insetion(<<) operator called" << std::endl;
	#endif
	out << obj.toFloat();
	return (out);
}

Fixed	Fixed::operator+(const Fixed &x) const
{
	#ifdef DEBUG
		std::cout << "Fixed: Arithmetic(+) operator called" << std::endl;
	#endif
	return (this->toFloat() + x.toFloat());
}

Fixed	Fixed::operator-(const Fixed &x) const
{
	#ifdef DEBUG
		std::cout << "Fixed: Arithmetic(-) operator called" << std::endl;
	#endif
	return (this->toFloat() - x.toFloat());
}

Fixed	Fixed::operator*(const Fixed &x) const
{
	#ifdef DEBUG
		std::cout << "Fixed: Arithmetic(*) operator called" << std::endl;
	#endif
	return (this->toFloat() * x.toFloat());
}

Fixed	Fixed::operator/(const Fixed &x) const
{
	#ifdef DEBUG
		std::cout << "Fixed: Arithmetic(/) operator called" << std::endl;
	#endif
	return (this->toFloat() / x.toFloat());
}

bool	Fixed::operator==(const Fixed &cmp) const
{
	#ifdef DEBUG
		std::cout << "Fixed: Comparison(==) operator called" << std::endl;
	#endif
	return (this->getRawBits() == cmp.getRawBits());
}

bool	Fixed::operator!=(const Fixed &cmp) const
{
	#ifdef DEBUG
		std::cout << "Fixed: Comparison(!=) operator called" << std::endl;
	#endif
	return (this->getRawBits() != cmp.getRawBits());
}

bool	Fixed::operator<(const Fixed &cmp) const
{
	#ifdef DEBUG
		std::cout << "Fixed: Comparison(<) operator called" << std::endl;
	#endif
	return (this->getRawBits() < cmp.getRawBits());
}

bool	Fixed::operator>(const Fixed &cmp) const
{
	#ifdef DEBUG
		std::cout << "Fixed: Comparison(>) operator called" << std::endl;
	#endif
	return (this->getRawBits() > cmp.getRawBits());
}

bool	Fixed::operator>=(const Fixed &cmp) const
{
	#ifdef DEBUG
		std::cout << "Fixed: Comparison(>=) operator called" << std::endl;
	#endif
	return (*this > cmp || *this == cmp);
}

bool	Fixed::operator<=(const Fixed &cmp) const
{
	#ifdef DEBUG
		std::cout << "Fixed: Comparison(<=) operator called" << std::endl;
	#endif
	return (*this < cmp || *this == cmp);
}

Fixed	&Fixed::operator++()
{
	#ifdef DEBUG
		std::cout << "Fixed: Pre-Increment operator called" << std::endl;
	#endif
	this->_fixedPoint++;
	return (*this);
}

Fixed	&Fixed::operator--()
{
	#ifdef DEBUG
		std::cout << "Fixed: Pre-Decrement operator called" << std::endl;
	#endif
	this->_fixedPoint--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	#ifdef DEBUG
		std::cout << "Fixed: Post-Increment operator called" << std::endl;
	#endif
	Fixed	tmp = *this;
	this->_fixedPoint++;
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	#ifdef DEBUG
		std::cout << "Fixed: Post-Decrement operator called" << std::endl;
	#endif
	Fixed	tmp = *this;
	this->_fixedPoint--;
	return (tmp);
}
