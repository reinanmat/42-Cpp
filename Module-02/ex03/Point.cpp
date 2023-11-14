/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:11:00 by revieira          #+#    #+#             */
/*   Updated: 2023/11/14 16:18:26 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0))
{
	#ifdef DEBUG
		std::cout << "Point: Default Constructor Called" << std::endl;
	#endif
}

Point::Point(const Point &obj)
{
	#ifdef DEBUG
		std::cout << "Point: Copy Constructor Called" << std::endl;
	#endif
	if (this != &obj)
		*this = obj;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
	#ifdef DEBUG
		std::cout << "Point: Constructor Called" << std::endl;
	#endif
}

Point::~Point()
{
	#ifdef DEBUG
		std::cout << "Point: Destructor Called" << std::endl;
	#endif
}

float	Point::getX(void) const
{
	#ifdef DEBUG
		std::cout << "getX member function called" << std::endl;
	#endif
	return (this->_x.toFloat());
}

float	Point::getY(void) const
{
	#ifdef DEBUG
		std::cout << "getY member function called" << std::endl;
	#endif
	return (this->_y.toFloat());
}

Point	&Point::operator=(const Point &other)
{
	#ifdef DEBUG
		std::cout << "Point: Copy Assignment Operator Called" << std::endl;
	#endif
	if (this != &other)
	{
		this->~Point();
		new(this) Point(other._x.toFloat(), other._y.toFloat());
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Point &obj)
{
	#ifdef DEBUG
		std::cout << "Point: Insertion(<<) Operator Called" << std::endl;
	#endif
	out << "(" << obj.getX() << ", " << obj.getY() << ")";
	return (out);
}
