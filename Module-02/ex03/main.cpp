/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:55:59 by revieira          #+#    #+#             */
/*   Updated: 2023/10/31 20:30:15 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point	v1(0, 3);
	Point	v2(-2, -2);
	Point	v3(2, -2);
	Point	point(0, 0);

	std::cout << "The point (" << point.getX() << ", " << point.getY() << ")" << std::endl;
	if (bsp(v1, v2, v3, point))
		 std::cout << "is inside the triangle"  << std::endl;
	else
		std::cout << "is not inside the triangle" << std::endl;
	return (0);
}
