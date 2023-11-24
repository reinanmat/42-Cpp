/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:09 by revieira          #+#    #+#             */
/*   Updated: 2023/11/24 17:17:29 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cstdlib>

static void	clapTrapFight(std::string a, std::string b)
{
	int			attacker;
	int			defender;
	ClapTrap	ClapTraps[] = {
		ClapTrap(a),
		ClapTrap(b),
	};

	ClapTraps[0].setAttackDamage(2);
	ClapTraps[1].setAttackDamage(2);
	ClapTraps[0].setHits(50);
	ClapTraps[1].setHits(50);
	ClapTraps[0].setEnergyPoints(50);
	ClapTraps[1].setEnergyPoints(50);
	srand(time(NULL));
	ClapTraps[0].printStatus();
	ClapTraps[1].printStatus();
	std::cout << std::endl;
	std::cout << CYN "=============THE-BATTLE-HAS-BEGIN=============" RESET << std::endl;
	std::cout << std::endl;
	while ((ClapTraps[0].getHits() != 0 && ClapTraps[1].getHits() != 0) &&
			(ClapTraps[0].getEnergyPoints() != 0 && ClapTraps[1].getEnergyPoints() != 0))
	{
		attacker = rand() % 2;
		defender = (attacker + 1 + 2) % 2;
		ClapTraps[attacker].attack(ClapTraps[defender].getName());
		ClapTraps[defender].takeDamage(ClapTraps[attacker].getAttackDamage());
	}
	std::cout << std::endl;
	std::cout << CYN "==============THE-BATTLE-IS-OVER==============" RESET << std::endl;
	if ((ClapTraps[0].getHits() != 0 && ClapTraps[1].getHits() == 0))
		std::cout << GRN << ClapTraps[0].getName() << " is the winner!";
	else if ((ClapTraps[1].getHits() != 0 && ClapTraps[0].getHits() == 0))
		std::cout << GRN << ClapTraps[1].getName() << " is the winner!";
	else if (ClapTraps[0].getHits() > ClapTraps[1].getHits())
		std::cout << GRN << ClapTraps[0].getName() << " is the winner!";
	else if (ClapTraps[1].getHits() > ClapTraps[0].getHits())
		std::cout << GRN << ClapTraps[1].getName() << " is the winner!";
	else
		std::cout << YEL << "Draw!";
	std::cout << RESET << std::endl;
	ClapTraps[0].printStatus();
	ClapTraps[1].printStatus();
}

int	main(void)
{
	{
		std::cout << "TEST 1" << std::endl;
		std::cout << "Constructors: " << std::endl;

		ClapTrap	oal("Oal");

		std::cout << std::endl;

		oal.printStatus();
		oal.attack("anything");

		std::cout << std::endl;

		std::cout << "Destructors:" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2" << std::endl;
		std::cout << "Constructors: " << std::endl;
		ClapTrap	oal("Oal");
		ClapTrap	riny("Riny");
		std::cout << std::endl;

		oal.setAttackDamage(3);
		oal.attack(riny.getName());
		riny.takeDamage(oal.getAttackDamage());
		riny.attack(oal.getName());
		oal.takeDamage(riny.getAttackDamage());
		std::cout << std::endl;

		oal.printStatus();
		riny.printStatus();
		std::cout << "Destructors:" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3" << std::endl;
		std::cout << "Constructors: " << std::endl;
		ClapTrap	flopi;
		ClapTrap	kobi("Kobi");
		std::cout << std::endl;

		flopi = kobi;
		flopi.setName("Flopi");
		std::cout << std::endl;

		flopi.printStatus();
		kobi.printStatus();
		for (int i = 0; i < 11; i++)
		{
			flopi.beRepaired(2);
			kobi.beRepaired(1);
		}
		flopi.attack(kobi.getName());
		flopi.printStatus();
		kobi.printStatus();
		std::cout << std::endl;
		std::cout << "Destructors:" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 4" << std::endl;
		std::cout << CYN "=================CLAP-FIGHT===================" RESET << std::endl;
		clapTrapFight("Oal", "Riny");
	}
	return (0);
}
