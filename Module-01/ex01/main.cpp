/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:14:38 by revieira          #+#    #+#             */
/*   Updated: 2023/10/20 18:53:16 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <unistd.h>

int	main(void)
{
	Zombie *horde;
	
	horde = zombieHorde(100, "zombie");
	for (int i = 0; i < 100; i++) {
		horde[i].announce();
	}
	delete[] horde;
}
