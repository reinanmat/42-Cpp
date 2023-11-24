/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:09 by revieira          #+#    #+#             */
/*   Updated: 2023/11/24 16:56:21 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

int	main(void)
{
	{
		std::cout << "Test 1" << std::endl;
		std::cout << "Constructors:" << std::endl;

		DiamondTrap	diamond("Diamond");

		std::cout << std::endl;

		diamond.guardGate();
		diamond.highFivesGuys();
		diamond.whoAmI();
		diamond.printStatus();

		std::cout << std::endl;
		std::cout << "Destructors:" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "Test 2" << std::endl;
		std::cout << "Constructors:" << std::endl;

		ClapTrap	clap("Clap");
		ScavTrap	scav("Scav");
		FragTrap	frag("Frag");
		DiamondTrap	diamond("Diamond");

		std::cout << std::endl;

		clap.printStatus();
		frag.printStatus();
		scav.printStatus();
		diamond.printStatus();

		clap.attack(diamond.getName());
		diamond.takeDamage(clap.getAttackDamage());
		scav.attack(diamond.getName());
		diamond.takeDamage(scav.getAttackDamage());
		frag.attack(diamond.getName());
		diamond.takeDamage(frag.getAttackDamage());

		diamond.attack(clap.getName());
		clap.takeDamage(diamond.getAttackDamage());
		diamond.attack(scav.getName());
		scav.takeDamage(diamond.getAttackDamage());
		diamond.attack(frag.getName());
		frag.takeDamage(diamond.getAttackDamage());

		clap.printStatus();
		scav.printStatus();
		frag.printStatus();
		diamond.printStatus();

		std::cout << std::endl;
		std::cout << "Destructors:" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "Test 3" << std::endl;
		std::cout << "Constructors:" << std::endl;

		DiamondTrap	diamond("Diamond");

		std::cout << std::endl;
		
		diamond.printStatus();
		diamond.whoAmI();

		diamond.setName("OtherName");
		diamond.printStatus();
		diamond.whoAmI();

		std::cout << std::endl;
		std::cout << "Destructors:" << std::endl;
	}
	return (0);
}
