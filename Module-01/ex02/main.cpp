/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:34:15 by revieira          #+#    #+#             */
/*   Updated: 2023/10/26 16:54:42 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "The memory address of the STRING:\t" << &string << std::endl;
	std::cout << "The memory address held by STRINGPTR:\t" << stringPTR << std::endl;
	std::cout << "The memory address held by STRINGREF:\t" << &stringREF << std::endl;

	std::cout << "The value of the STRING:\t\t" << string << std::endl;
	std::cout << "The value pointed to by STRINGPTR:\t" << *stringPTR << std::endl;
	std::cout << "The value pointed to by STRINGREF:\t" << stringREF << std::endl;
	return (0);
}
