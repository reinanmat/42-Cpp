/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:40:06 by revieira          #+#    #+#             */
/*   Updated: 2023/12/15 14:45:15 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <cstring>

#define MAX_SLOTS 4

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(const Character &obj);
		~Character();
		Character &operator=(const Character &other);
		std::string const &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	
	private:
		int			_currSize;
		std::string	_name;
		AMateria	*_inventory[MAX_SLOTS];
};
