/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:14:38 by revieira          #+#    #+#             */
/*   Updated: 2023/10/02 19:32:57 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <unistd.h>

int	main(void)
{
	Zombie *horde;
	
	horde = zombieHorde(10, "douglas");
	for (int i = 0; i < 10; i++) {
		try {
			horde[i].announce();
		}
		catch (...) {
			std::cout << "Error" << std::endl;
		}
	}
	delete[] horde;
}
