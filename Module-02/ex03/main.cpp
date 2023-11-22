/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:55:59 by revieira          #+#    #+#             */
/*   Updated: 2023/11/22 15:48:15 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	{
		std::cout << "TEST 1" << std::endl;
		Point a(1.0, 1.0);
		Point b(a);
		Point c;

		std::cout << "point a" << a << std::endl;
		std::cout << "point b" << b << std::endl;
		std::cout << "(before assignment)point c" << c << std::endl;
		c = b;
		std::cout << "(after assignment)point c" << c << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "TEST 2" << std::endl;
		Point	v1;
		Point	v2;
		Point	v3;
		Point	point;

		v1 = Point(0, 3);
		v2 = Point(-2, -2);
		v3 = Point(2, -2);
		std::cout << "triangle: v1" << v1 << " v2" << v2 << " v3" << v3 << std::endl;
		point = Point(0.5f, 1);
		std::cout << "point" << point;
		std::cout << (bsp(v3, v2, v1, point) ? INSIDE : NOT_INSIDE) << std::endl;
		point = Point(0, 1);
		std::cout << "point" << point;
		std::cout << (bsp(v1, v2, v3, point) ? INSIDE : NOT_INSIDE) << std::endl;
		point = Point(0, 3.25f);
		std::cout << "point" << point;
		std::cout << (bsp(v1, v2, v3, point) ? INSIDE : NOT_INSIDE) << std::endl;
		point = Point(5, 5);
		std::cout << "point" << point;
		std::cout << (bsp(v1, v2, v3, point) ? INSIDE : NOT_INSIDE) << std::endl;

		v1 = Point(0, 0);
		v2 = Point(0, 2);
		v3 = Point(2, 0);
		std::cout << "\ntriangle: v1" << v1 << " v2" << v2 << " v3" << v3 << std::endl; 
		point = Point(0, 0);
		std::cout << "point" << point;
		std::cout << (bsp(v1, v2, v3, point) ? INSIDE : NOT_INSIDE) << std::endl;
		point = Point(1, 1);
		std::cout << "point" << point;
		std::cout << (bsp(v1, v2, v3, point) ? INSIDE : NOT_INSIDE) << std::endl;
		point = Point(0.5f, 0.5f);
		std::cout << "point" << point;
		std::cout << (bsp(v1, v2, v3, point) ? INSIDE : NOT_INSIDE) << std::endl;
		point = Point(-0.5f, 0.5f);
		std::cout << "point" << point;
		std::cout << (bsp(v1, v2, v3, point) ? INSIDE : NOT_INSIDE) << std::endl;

		v1 = Point(0, 2);
		v2 = Point(0, 1);
		v3 = Point(2, 0);
		std::cout << "\ntriangle: v1" << v1 << " v2" << v2 << " v3" << v3 << std::endl; 
		point = Point(0, 0);
		std::cout << "point" << point;
		std::cout << (bsp(v1, v2, v3, point) ? INSIDE : NOT_INSIDE) << std::endl;
		point = Point(0.5f, 1);
		std::cout << "point" << point;
		std::cout << (bsp(v1, v2, v3, point) ? INSIDE : NOT_INSIDE) << std::endl;
		point = Point(1, 1);
		std::cout << "point" << point;
		std::cout << (bsp(v1, v2, v3, point) ? INSIDE : NOT_INSIDE) << std::endl;
		point = Point(0.25f, 1.5f);
		std::cout << "point" << point;
		std::cout << (bsp(v1, v2, v3, point) ? INSIDE : NOT_INSIDE) << std::endl;
	}
	return (0);
}
