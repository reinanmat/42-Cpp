/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:05:06 by revieira          #+#    #+#             */
/*   Updated: 2023/11/22 14:43:12 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

#define INSIDE		GRN" is inside the triangle " RESET
#define NOT_INSIDE	RED" is not inside the triangle " RESET

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

	private:
		Fixed const _x;
		Fixed const _y;
};

std::ostream	&operator<<(std::ostream &out, const Point &obj);
bool			bsp(Point const a, Point const b, Point const c, Point const point);
