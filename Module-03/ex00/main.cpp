/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:09 by revieira          #+#    #+#             */
/*   Updated: 2023/11/22 18:57:11 by revieira         ###   ########.fr       */
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
	std::cout << CYN "=============THE-BATTLE-HAS-BEGIN=============" RESET << std::endl;
	ClapTraps[0].printStatus();
	ClapTraps[1].printStatus();
	while ((ClapTraps[0].getHits() != 0 && ClapTraps[1].getHits() != 0) &&
			(ClapTraps[0].getEnergyPoints() != 0 && ClapTraps[1].getEnergyPoints() != 0))
	{
		attacker = rand() % 2;
		defender = (attacker + 1 + 2) % 2;
		ClapTraps[attacker].attack(ClapTraps[defender].getName());
		ClapTraps[defender].takeDamage(ClapTraps[attacker].getAttackDamage());
	}
	std::cout << CYN "==============THE-BATTLE-IS-OVER==============" RESET << std::endl;
	ClapTraps[0].printStatus();
	ClapTraps[1].printStatus();
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
}

int	main(void)
{
	{
		std::cout << "TEST 1" << std::endl;
		ClapTrap	oal("Oal");
		ClapTrap	riny("Riny");

		oal.setAttackDamage(3);
		oal.attack(riny.getName());
		riny.takeDamage(oal.getAttackDamage());
		riny.attack(oal.getName());
		oal.takeDamage(riny.getAttackDamage());

		oal.printStatus();
		riny.printStatus();
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 2" << std::endl;
		ClapTrap	flopi;
		ClapTrap	kobi("Kobi");

		flopi = kobi;
		flopi.setName("Flopi");

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
	}
	std::cout << std::endl;
	{
		std::cout << "TEST 3" << std::endl;
		clapTrapFight("Oal", "Riny");
	}
	return (0);
}
