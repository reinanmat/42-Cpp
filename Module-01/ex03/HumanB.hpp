/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:12:22 by revieira          #+#    #+#             */
/*   Updated: 2023/10/04 14:28:45 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	public:
		HumanB();
		~HumanB();
		HumanB(std::string name);
		void	setWeapon(Weapon& weapon);
		void	attack(void);
	private:
		Weapon		*weapon;
		std::string	name;
};
