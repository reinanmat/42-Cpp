/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:23:06 by revieira          #+#    #+#             */
/*   Updated: 2023/10/02 18:02:02 by revieira         ###   ########.fr       */
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
		Zombie& 	operator=(const Zombie other);
	private:
		std::string	_name;
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif
