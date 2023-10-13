/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:59:00 by revieira          #+#    #+#             */
/*   Updated: 2023/10/13 13:47:37 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	validProblem(std::string parameter)
{
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};
	
	for (int i = 0; i < 4; i++)
		if (levels[i] == parameter)
			return (i + 1);
	return (0);
}

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "Error: Invalid number of parameters" << std::endl;
		return (1);
	}
	switch (validProblem(argv[1])) {
		case 0:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
		case 1:
			harl.complain(0);
		case 2:
			harl.complain(1);
		case 3:
			harl.complain(2);
		case 4:
			harl.complain(3);
	}
	return (0);
}
