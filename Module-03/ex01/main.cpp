/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:09 by revieira          #+#    #+#             */
/*   Updated: 2023/11/24 14:54:20 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	{
		std::cout << "TEST 1" << std::endl;
		std::cout << "Constructors:" << std::endl;

		ClapTrap	oal("Oal");
		ScavTrap	riny("Riny");

		std::cout << std::endl;

		riny.attack(oal.getName());
		oal.takeDamage(riny.getAttackDamage());
		oal.printStatus();
		riny.printStatus();
		riny.guardGate();

		std::cout << std::endl;

		std::cout << "Destructors:" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2" << std::endl;
		std::cout << "Constructors:" << std::endl;

		ScavTrap	oal;
		ScavTrap	riny;

		std::cout << std::endl;

		oal.printStatus();
		riny.printStatus();

		std::cout << std::endl;

		riny = ScavTrap("Riny");
		oal = riny;
		oal.setName("Oal");

		std::cout << std::endl;

		oal.printStatus();
		riny.printStatus();

		std::cout << std::endl;
		std::cout << "Destructors:" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3" << std::endl;
		std::cout << "Constructors:" << std::endl;

		ScavTrap oal("Oal");
		ClapTrap riny("Riny");

		std::cout << std::endl;

		riny.setAttackDamage(999);
		oal.printStatus();
		riny.printStatus();

		riny.attack(oal.getName());
		oal.takeDamage(riny.getAttackDamage());
		oal.beRepaired(999);

		oal.printStatus();
		riny.printStatus();

		std::cout << std::endl;
		std::cout << "Destructors:" << std::endl;
	}
	return (0);
}
