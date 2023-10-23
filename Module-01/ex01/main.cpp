/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:14:38 by revieira          #+#    #+#             */
/*   Updated: 2023/10/23 13:45:04 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie		*horde;
	const int	hordeSize = 8;
	
	horde = zombieHorde(hordeSize, "zombie");
	for (int i = 0; i < hordeSize; i++) {
		horde[i].announce();
	}
	delete[] horde;
}
