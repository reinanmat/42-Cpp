/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:09 by revieira          #+#    #+#             */
/*   Updated: 2023/10/09 13:31:08 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <cstdlib>

static void	r(std::string a, std::string b)
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
	std::cout << "=========The battle has begin==========" << std::endl;
	while ((ClapTraps[0].getHits() != 0 && ClapTraps[1].getHits() != 0) &&
			(ClapTraps[0].getEnergyPoints() != 0 && ClapTraps[1].getEnergyPoints() != 0))
	{
		attacker = rand() % 2;
		defender = (attacker + 1 + 2) % 2;
		ClapTraps[attacker].attack(ClapTraps[defender].getName());
		ClapTraps[defender].takeDamage(ClapTraps[attacker].getAttackDamage());
	}
	std::cout << "=========The battle is over=========" << std::endl;
	if ((ClapTraps[0].getHits() != 0 && ClapTraps[1].getHits() == 0))
		std::cout << ClapTraps[0].getName() << " is the winner!" << std::endl;
	else if ((ClapTraps[1].getHits() != 0 && ClapTraps[0].getHits() == 0))
		std::cout << ClapTraps[1].getName() << " is the winner!" << std::endl;
	else if (ClapTraps[0].getHits() > ClapTraps[1].getHits())
		std::cout << ClapTraps[0].getName() << " is the winner!" << std::endl;
	else if (ClapTraps[1].getHits() > ClapTraps[0].getHits())
		std::cout << ClapTraps[1].getName() << " is the winner!" << std::endl;
	else
		std::cout << "Draw!" << std::endl;
}

int	main(void)
{
	r("Oal", "Rinh");
	return (0);
}
