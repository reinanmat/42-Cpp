/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getInput.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:37:28 by revieira          #+#    #+#             */
/*   Updated: 2023/10/20 18:20:29 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	checkEmptyField(std::string	str)
{
	size_t	i;

	if (str.empty())
		return (1);
	i = 0;
	while (isspace(str[i]))
		i++;
	if (i == str.size())
		return (1);
	return (0);
}

int	checkNumber(std::string number)
{
	size_t	i;

	i = 0;
	while (i < number.size())
	{
		if (!isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int	checkUnicode(std::string str)
{
	size_t	i;

	i = 0;
	while (i < str.size())
	{
		if (!isascii(str[i]))
			return (1);
		i++;
	}
	return (0);
}

std::string	getInput(std::string key)
{
	std::string	input;

	while (1)
	{
		std::cout << key << ": ";
		if (!std::getline(std::cin, input))
			exit(1);
		if (checkEmptyField(input))
			std::cout << RED "Error: Empty field" RESET<< std::endl;
		else if (checkUnicode(input))
			std::cout << RED "Error: Unsupported unicode characters" RESET << std::endl;
		else if (key == "phone book" && !checkNumber(input))
			std::cout << RED "Error: Not a valid phone number" RESET << std::endl;
		else
			break;
	}
	return (input);
}
