/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:34:15 by revieira          #+#    #+#             */
/*   Updated: 2023/10/02 19:42:00 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	stringPTR;
	std::string	stringREF;

	stringPTR = string;
	stringREF = string;
}
