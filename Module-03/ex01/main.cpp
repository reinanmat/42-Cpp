/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:08:09 by revieira          #+#    #+#             */
/*   Updated: 2023/10/09 18:17:35 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <cstdlib>

int	main(void)
{
	ClapTrap	oal("Oal");
	ScavTrap	rinh("Rinh");
	
	rinh.attack(oal.getName());
	oal.takeDamage(rinh.getAttackDamage());
	oal.printStatus();
	rinh.printStatus();
	rinh.guardGate();
	return (0);
}
