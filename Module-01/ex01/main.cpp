/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:14:38 by revieira          #+#    #+#             */
/*   Updated: 2023/10/26 14:55:17 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	{
		std::cout << "TEST 1" << std::endl;
		Zombie		*horde;
		const int	hordeSize = 10;

		horde = zombieHorde(hordeSize, "Bob");
		for (int i = 0; i < hordeSize; i++) {
			horde[i].announce();
		}
		delete[] horde;
	}
	{
		std::cout << "TEST 2" << std::endl;
		Zombie		*horde;
		const int	hordeSize = 5;

		horde = zombieHorde(hordeSize, "Ignored Zombie");
		horde[0].setName("First Zombie");
		horde[hordeSize/2].setName("Middle Zombie");
		horde[hordeSize - 1].setName("Last Zombie");
		for (int i = 0; i < hordeSize; i++) {
			horde[i].announce();
		}
		delete[] horde;
	}
}
