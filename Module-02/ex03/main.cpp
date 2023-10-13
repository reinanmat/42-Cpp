/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:55:59 by revieira          #+#    #+#             */
/*   Updated: 2023/10/13 16:57:23 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point	v1(0, 0);
	Point	v2(0, 100);
	Point	v3(100, 0);
	Point	point(0.3, 0.3);

	std::cout << "The point (" << point.getX() << ", " << point.getY() << ")" << std::endl;
	if (bsp(point, v1, v2, v3))
		 std::cout << "is inside the triangle"  << std::endl;
	else
		std::cout << "is not inside the triangle" << std::endl;
	return (0);
}
