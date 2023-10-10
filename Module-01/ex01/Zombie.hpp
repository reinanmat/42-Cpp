/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:23:06 by revieira          #+#    #+#             */
/*   Updated: 2023/10/02 19:30:09 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void		announce(void);
		std::string	getName(void);
		void		setName(std::string name);
		Zombie& 	operator=(const Zombie other);
	private:
		std::string	_name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif