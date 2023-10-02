/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:17:23 by revieira          #+#    #+#             */
/*   Updated: 2023/10/02 18:42:19 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string	names[] = {"Jubileu", "Cleiton", "Funestos"};
	for (int i = 0; i != 3; i++)
		randomChump(names[(i + 1 + 3) % 3]);
	return (0);
}
