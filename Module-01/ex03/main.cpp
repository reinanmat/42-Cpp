/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:45:20 by revieira          #+#    #+#             */
/*   Updated: 2023/10/26 17:12:40 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	{
		std::cout << "TEST 1" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		std::cout << "TEST 2" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		std::cout << "TEST 3" << std::endl;
		Weapon	sword = Weapon("Long Sword");
		HumanA	bob("Bob", sword);
		bob.attack();
		sword.setType("Large sword");
		bob.attack();

		Weapon	bow = Weapon("Short Bow");
		HumanB	jim("Jim");
		jim.setWeapon(bow);
		jim.attack();
		bow.setType("Long Bow");
		jim.attack();
	}
	{
		std::cout << "TEST 4" << std::endl;
		Weapon	*invalidWeapon = NULL;
		HumanA	jim("Jim", *invalidWeapon);
		HumanB	bob("Bob"); 
		jim.attack();
		bob.attack();
		bob.setWeapon(*invalidWeapon);
		bob.attack();
	}
}
