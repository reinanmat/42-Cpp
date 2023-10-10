/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:09 by revieira          #+#    #+#             */
/*   Updated: 2023/10/10 18:29:08 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <cstdlib>

int	main(void)
{
	{
		ClapTrap	oal("Oal");
		ScavTrap	riny("Riny");
		FragTrap	flokis("Flokis");

		oal.printStatus();
		riny.printStatus();
		flokis.printStatus();
		flokis.highFivesGuys();
	}
	std::cout << std::endl;
	{
		FragTrap	oal("Oal");
		FragTrap	flokis;

		flokis = oal;
		flokis.setName("Flokis");
		flokis.setHits(999);
		flokis.setEnergyPoints(999);
		flokis.setAttackDamage(999);
		flokis.printStatus();
	}
	return (0);
}
