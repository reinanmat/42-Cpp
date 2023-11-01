/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:11:00 by revieira          #+#    #+#             */
/*   Updated: 2023/11/01 16:39:59 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
	/* std::cout << "Point: Default Constructor Called" << std::endl; */
	this->_x = Fixed(0);
	this->_y = Fixed(0);
}

Point::Point(const Point &obj)
{
	/* std::cout << "Point: Copy Constructor Called" << std::endl; */
	if (this != &obj)
		*this = obj;
}

Point::Point(const float x, const float y)
{
	/* std::cout << "Point: Constructor Called" << std::endl; */
	this->_x = Fixed(x);
	this->_y = Fixed(y);
}

Point::~Point()
{
	/* std::cout << "Point: Destructor Called" << std::endl; */
}

float	Point::getX(void) const
{
	return (this->_x.toFloat());
}

float	Point::getY(void) const
{
	return (this->_y.toFloat());
}

Point	&Point::operator=(const Point &other)
{
	/* std::cout << "Point: Copy Assignment Operator Called" << std::endl; */
	if (this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Point &obj)
{
	out << "(" << obj.getX() << ", " << obj.getY() << ")";
	return (out);
}
