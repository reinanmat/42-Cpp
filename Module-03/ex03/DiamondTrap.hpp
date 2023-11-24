/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:54:54 by revieira          #+#    #+#             */
/*   Updated: 2023/11/24 16:27:31 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(DiamondTrap const &obj);
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap	&operator=(const DiamondTrap &other);
		std::string	getName(void) const;
		std::string	getClapName(void) const;
		void		setName(std::string name);
		void		whoAmI();
		void		attack(const std::string &target);
		void		printStatus(void) const;

	private:
		std::string	_name;
};
