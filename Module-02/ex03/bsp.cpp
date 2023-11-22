/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:27:21 by revieira          #+#    #+#             */
/*   Updated: 2023/11/22 14:43:38 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed	calculateAreaOfTriangle(Point const a, Point const b, const Point c)
{
	Fixed	area;
	Fixed	aux;
	
	aux = std::fabs(a.getX() * (b.getY() - c.getY()) +
				 b.getX() * (c.getY() - a.getY()) +
				 c.getX() * (a.getY()- b.getY()));
	area = Fixed(0.5f) * aux;
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	triangleABC;
	Fixed	triangleABP;
	Fixed	triangleBCP;
	Fixed	triangleACP;

	triangleABC = calculateAreaOfTriangle(a, b, c);
	triangleABP = calculateAreaOfTriangle(a, b, point);
	triangleBCP = calculateAreaOfTriangle(b, c, point);
	triangleACP = calculateAreaOfTriangle(a, c, point);
	if (triangleABP == Fixed(0) || triangleBCP == Fixed(0) || triangleACP == Fixed(0))
		return (false);
	return (triangleABC == triangleACP + triangleBCP + triangleABP);
}
