/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:17:23 by revieira          #+#    #+#             */
/*   Updated: 2023/10/20 18:45:02 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string	names[] = {"Jubileu", "Cleiton", "Funestos"};

	for (int i = 0; i != 5; i++)
		randomChump(names[(i + 3) % 3]);
	Zombie *zombie1 = newZombie("Zombie1");
	Zombie *zombie2 = newZombie("Zombie2");
	zombie1->announce();
	zombie2->announce();
	delete zombie1;
	delete zombie2;
	return (0);
}
