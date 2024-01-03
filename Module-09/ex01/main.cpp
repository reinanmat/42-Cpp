/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:05:01 by revieira          #+#    #+#             */
/*   Updated: 2024/01/03 18:36:20 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool	validNotation(std::string parameters)
{
	std::string			word;
	std::stringstream	ss(parameters);
	std::stack<int>		stack;
	while (ss >> word)
	{
		if (!isNumber(word) && checkOperation(word) == -1)
			return (false);
		else if (isNumber(word))
			stack.push(1);
		else
		{
			if (stack.size() < 2)
				return (false);
			stack.pop();
			stack.pop();
			stack.push(1);
		}
	}
	return (stack.size() == 1);
}

static bool	validArgs(int argc, char **argv)
{
	if (argc != 2)
		return (false);
	if (!validNotation(argv[1]))
		return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	if (!validArgs(argc, argv))
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	rpn(argv[1]);
	return (0);
}
