/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:11:12 by revieira          #+#    #+#             */
/*   Updated: 2023/10/09 18:53:04 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	protected:
		static const int defaultHits = 100;
		static const int defaultEnergyPoints = 100;
		static const int defaultAttackDamage = 30;

	public:
		FragTrap();
		FragTrap(FragTrap const &obj);
		FragTrap(std::string name);
		~FragTrap();
		FragTrap&	operator=(const FragTrap &cpy);
		void		highFivesGuys(void);
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};
