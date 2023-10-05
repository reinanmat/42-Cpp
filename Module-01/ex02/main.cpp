/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:34:15 by revieira          #+#    #+#             */
/*   Updated: 2023/10/05 13:40:50 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = *&string;

	std::cout << "The memory address of the STRING: " << &string << std::endl;
	std::cout << "The memory address of the STRINGPTR: " << stringPTR << std::endl;
	std::cout << "The memory address of the STRINGREF: " << &stringREF << std::endl;

	std::cout << "The memory address of the STRING: " << string << std::endl;
	std::cout << "The memory address of the STRINGPTR: " << *stringPTR << std::endl;
	std::cout << "The memory address of the STRINGREF: " << stringREF << std::endl;
	return (0);
}
