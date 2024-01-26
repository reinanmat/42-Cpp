/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:21:32 by revieira          #+#    #+#             */
/*   Updated: 2024/01/26 18:11:54 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm>
#include <ctime>
#include <limits>

static bool withinLimits(const std::string &str)
{
	long long	n;
	std::stringstream	ss(str);
	ss >> n;

	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
		return (false);
	return (true);
}

static bool isPositiveNumber(const std::string &str)
{
	std::string::const_iterator     it = str.begin();

	if (*it == '+' && str.size() > 1)
		it++;
	while (it != str.end() && std::isdigit(*it))
		it++;
	return (!str.empty() && it == str.end());
}

static bool	hasDuplicateNumber(std::vector<int> &vec)
{
	std::vector<int>::iterator	curr = vec.begin();
	std::vector<int>::iterator	next = vec.begin() + 1;

	while (next != vec.end())
	{
		if (*curr == *next)
			return (true);
		curr++;
		next++;
	}
	return (false);
}

static bool	validArgs(int argc, char **argv)
{
	if (argc == 1)
		return (false);
	for (int i = 1; i < argc; i++)
		if (!isPositiveNumber(argv[i]) || !withinLimits(argv[i]))
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

	argv++;
	std::vector<int>	vec = createContainer<std::vector<int> >(argc - 1, argv);
	std::deque<int>		deq = createContainer<std::deque<int> >(argc - 1, argv);
	std::vector<int>	expectedVector(vec);
	std::deque<int>		expectedDeque(deq);
	PmergeMe			pmerge(vec, deq);

	std::sort(expectedVector.begin(), expectedVector.end());
	std::sort(expectedDeque.begin(), expectedDeque.end());
	if (hasDuplicateNumber(expectedVector))
	{
		std::cerr << "Error: Contains duplicate numbers" << std::endl;
		return (1);
	}
	if (expectedVector == vec)
	{
		std::cerr << "Error: Numbers already sorted" << std::endl;
		return (1);
	}


	std::clock_t	start;
	float			vecTime;
	float			deqTime;

	std::cout << "VECTOR:" << std::endl;
	start = clock();
	pmerge.sort(VECTOR);
	vecTime = clock() - start;

	std::cout << "DEQUE:" << std::endl;
	start = clock();
	pmerge.sort(DEQUE);
	deqTime = clock() - start;

	std::cout << std::endl;

	std::cout << "Before:\t";
	printContainer(deq);
	std::cout << "After:\t";
	if (expectedVector == pmerge.getSortedVector() && expectedDeque == pmerge.getSortedDeque())
		printContainer(pmerge.getSortedDeque());
	else
	{
		std::cout << "ERROR: NOT SORTED: ";
		printContainer(pmerge.getSortedDeque());
	}
	
	std::cout << std::endl;

	std::cout << "Time to process a range of " << argc - 1 << " elements with ";
	std::cout << "std::vector:\t" << std::fixed << vecTime / CLOCKS_PER_SEC << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with ";
	std::cout << "std::deque:\t" << std::fixed << deqTime / CLOCKS_PER_SEC << " us" << std::endl;
	

	// std::cout << "Before:\t";
	// printArguments(argc, argv);
	// std::cout << "After:\t";
	// printContainer(vec, lst);
	return (0);
}
