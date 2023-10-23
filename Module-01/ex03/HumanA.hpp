/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:04:26 by revieira          #+#    #+#             */
/*   Updated: 2023/10/23 14:24:49 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
	public:
		HumanA();
		~HumanA();
		HumanA(std::string name, Weapon& weapon);
		void	attack(void);

	private:
		Weapon		*_weapon;
		std::string	_name;
};
