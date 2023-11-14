/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:05:06 by revieira          #+#    #+#             */
/*   Updated: 2023/11/14 16:27:48 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define INSIDE " is inside the triangle "
#define NOT_INSIDE " is not inside the triangle "

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(Point const &obj);
		Point(const float x, const float y);
		~Point();
		float	getX(void) const;
		float	getY(void) const;
		Point	&operator=(const Point &other);
		Point	operator-(const Point &b) const;
	private:
		Fixed const _x;
		Fixed const _y;
};

std::ostream	&operator<<(std::ostream &out, const Point &obj);
bool bsp(Point const a, Point const b, Point const c, Point const point);
