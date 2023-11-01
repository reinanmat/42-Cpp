/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:05:06 by revieira          #+#    #+#             */
/*   Updated: 2023/11/01 16:38:44 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(Point const &obj);
		Point(const float x, const float y);
		float	getX(void) const;
		float	getY(void) const;
		~Point();
		Point	&operator=(const Point &other);
		Point	operator-(const Point &b) const;
	private:
		Fixed _x;
		Fixed _y;
};

std::ostream	&operator<<(std::ostream &out, const Point &obj);
bool bsp(Point const a, Point const b, Point const c, Point const point);
