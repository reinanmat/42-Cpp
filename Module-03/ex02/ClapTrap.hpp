/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:51:34 by revieira          #+#    #+#             */
/*   Updated: 2023/11/22 17:45:21 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hits;
		int			_energyPoints;
		int			_attackDamage;

	public:
		ClapTrap();
		ClapTrap(ClapTrap const &obj);
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap	&operator=(const ClapTrap &other);
		std::string	getName(void) const;
		int			getHits(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;
		void		setName(std::string name);
		void		setHits(int hits);
		void		setEnergyPoints(int energyPoints);
		void		setAttackDamage(int attackDamage);
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		printStatus(void) const;

	private:
		static const int defaultHits = 10;
		static const int defaultEnergyPoints = 10;
		static const int defaultAttackDamage = 0;
};
