/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:09 by revieira          #+#    #+#             */
/*   Updated: 2023/10/10 18:23:26 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	{
		ClapTrap	oal("Oal");
		ScavTrap	riny("Riny");

		riny.attack(oal.getName());
		oal.takeDamage(riny.getAttackDamage());
		oal.printStatus();
		riny.printStatus();
		riny.guardGate();
	}
	std::cout << std::endl;
	{
		ClapTrap	oal;
		ClapTrap	riny;

		oal.printStatus();
		riny.printStatus();

		riny = ClapTrap("Riny");
		oal = riny;
		oal.setName("Oal");

		oal.printStatus();
		riny.printStatus();
	}
	return (0);
}
