/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:21:32 by revieira          #+#    #+#             */
/*   Updated: 2024/01/23 11:50:04 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool isPositiveNumber(const std::string &str)
{
	std::string::const_iterator     it = str.begin();

	if (*it == '+' && str.size() > 1)
		it++;
	while (it != str.end() && std::isdigit(*it))
		it++;
	return (!str.empty() && it == str.end());
}

static bool	validArgs(int argc, char **argv)
{
	if (argc == 1)
		return (false);
	for (int i = 1; i < argc; i++)
		if (!isPositiveNumber(argv[i]))
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
	std::vector<int>	vec;
	std::deque<int>		deque;
	for (int i = 1; i < argc; i++)
	{
		int num = std::atoi(argv[i]);
		vec.push_back(num);
		deque.push_back(num);
	}

	PmergeMe	pmerge(vec, deque);

	std::cout << "VECTOR:" << std::endl;
	pmerge.sort(VECTOR);
	std::cout << std::endl;


	std::cout << "DEQUE:" << std::endl;
	pmerge.sort(DEQUE);
	std::cout << std::endl;
	

	// std::cout << "Before:\t";
	// printArguments(argc, argv);
	// std::cout << "After:\t";
	// printContainer(vec, lst);
	return (0);
}
