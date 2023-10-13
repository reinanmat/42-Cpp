/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:27:21 by revieira          #+#    #+#             */
/*   Updated: 2023/10/13 16:57:04 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

float	dotProduct(Point a, Point b)
{
	return (a.getX() * b.getX() + a.getY() * b.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point	v1, v2, v3;
	
	v1 = c - a;
	v2 = b - a;
	v3 = point - a;

	float dot00 = dotProduct(v2, v1);
	float dot01 = dotProduct(v1, v2);
	float dot02 = dotProduct(v1, v3);
	float dot11 = dotProduct(v2, v2);
	float dot12 = dotProduct(v2, v3);

	float invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
	float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
	float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

	std::cout << invDenom << std::endl;
	std::cout << "u: " << u << std::endl;
	std::cout << "v: " << v << std::endl;
	return ((u >= 0) && (v >= 0) && (u + v < 1));
}
