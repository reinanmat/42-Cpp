/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:27:21 by revieira          #+#    #+#             */
/*   Updated: 2023/10/31 20:44:03 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed	calculateAreaOfTriangle(Point const a, Point const b, const Point c)
{
	Fixed	area;
	
	area = Fixed(0.5f) * Fixed(std::fabs(a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())));
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	triangle;
	Fixed	triangleABP;
	Fixed	triangleBCP;
	Fixed	triangleACP;

	triangle = calculateAreaOfTriangle(a, b, c);
	triangleABP = calculateAreaOfTriangle(a, b, point);
	triangleBCP = calculateAreaOfTriangle(b, c, point);
	triangleACP = calculateAreaOfTriangle(a, c, point);
	if (triangle == triangleACP + triangleBCP + triangleABP)
		return (true);
	else
		return (false);
}
