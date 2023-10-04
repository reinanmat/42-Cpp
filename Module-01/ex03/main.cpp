/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:45:20 by revieira          #+#    #+#             */
/*   Updated: 2023/10/04 14:32:39 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
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
