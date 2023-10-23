/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:51:55 by revieira          #+#    #+#             */
/*   Updated: 2023/10/23 15:51:59 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	printInUpperCase(std::string str)
{
	for (size_t i = 0; i < str.size(); i++) {
		std::cout << char(toupper(str[i]));
	}
}

int	main(int argc, char **argv)
{
	std::string str;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		argv++;
		for (int i = 0; i < argc - 1; i++) {
			str = argv[i];
			printInUpperCase(str);
		}
	}
	return (0);
}
