/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:48:06 by revieira          #+#    #+#             */
/*   Updated: 2023/10/10 18:09:30 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		static const int defaultHits = 100;
		static const int defaultEnergyPoints = 50;
		static const int defaultAttackDamage = 20;

	public:
		ScavTrap();
		ScavTrap(ScavTrap const &obj);
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap	&operator=(const ScavTrap &cpy);
		void		attack(const std::string &target);
		void		guardGate();
};
