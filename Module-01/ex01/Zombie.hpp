/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:23:06 by revieira          #+#    #+#             */
/*   Updated: 2023/10/20 18:49:53 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		Zombie		&operator=(const Zombie &other);
		std::string	getName(void);
		void		setName(std::string name);
		void		announce(void);

	private:
		std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);
