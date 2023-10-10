/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:09 by revieira          #+#    #+#             */
/*   Updated: 2023/10/10 18:12:35 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

int	main(void)
{
	{
		std::cout << "Test 2" << std::endl;
		ClapTrap	clap("Clap");
		clap.printStatus();
		std::cout << std::endl;

		ScavTrap	scav("Scav");
		scav.printStatus();
		std::cout << std::endl;

		FragTrap	frag("Frag");
		frag.printStatus();
		std::cout << std::endl;

		DiamondTrap	diamond("Diamond");
		diamond.printStatus();
		std::cout << std::endl;

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
	}
	{
		std::cout << std::endl << "Test 2" << std::endl;
		DiamondTrap	diamond;
		
		diamond = DiamondTrap("Test");

		diamond.setName("name");
		diamond.whoAmI();
	}
	return (0);
}
