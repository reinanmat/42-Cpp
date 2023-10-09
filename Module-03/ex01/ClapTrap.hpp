/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:51:34 by revieira          #+#    #+#             */
/*   Updated: 2023/10/06 17:57:27 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(ClapTrap const &obj);
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap	&operator=(const ClapTrap &cpy);
		void		setName(std::string name);
		void		setHits(int hits);
		void		setEnergyPoints(int energyPoints);
		void		setAttackDamage(int attackDamage);
		std::string	getName(void) const;
		int			getHits(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	private:
		std::string	_name;
		int			_hits;
		int			_energyPoints;
		int			_attackDamage;
};
