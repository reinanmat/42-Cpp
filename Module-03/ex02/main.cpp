/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:09 by revieira          #+#    #+#             */
/*   Updated: 2023/11/24 17:29:55 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << std::endl;
	{
		std::cout << "TEST 1" << std::endl;
		std::cout << "Constructors:" << std::endl;

		FragTrap	flokis("Flokis");

		std::cout << std::endl;

		flokis.printStatus();
		flokis.attack("ANYTHING");
		flokis.printStatus();
		flokis.highFivesGuys();

		std::cout << std::endl;
		std::cout << "Destructors:" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2" << std::endl;
		std::cout << "Constructors:" << std::endl;

		ClapTrap	oal("Oal");
		ScavTrap	riny("Riny");
		FragTrap	flokis("Flokis");

		std::cout << std::endl;

		oal.printStatus();
		riny.printStatus();
		flokis.printStatus();
		flokis.highFivesGuys();
		oal.attack(flokis.getName());
		flokis.takeDamage(oal.getAttackDamage());
		riny.attack(flokis.getName());
		flokis.takeDamage(riny.getAttackDamage());
		flokis.printStatus();

		std::cout << std::endl;
		std::cout << "Destructors:" << std::endl;
	}
	return (0);
}
