/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:11:12 by revieira          #+#    #+#             */
/*   Updated: 2023/10/10 18:13:20 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
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
		FragTrap&	operator=(const FragTrap &other);
		void		highFivesGuys(void);
};
