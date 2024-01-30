/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:21:32 by revieira          #+#    #+#             */
/*   Updated: 2024/01/30 15:55:49 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static bool withinLimits(const std::string &str)
{
	long long	n;
	std::stringstream	ss(str);
	ss >> n;

	if (n <= 0 || n > std::numeric_limits<int>::max())
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
	std::vector<int>	sorted(vec);
	std::sort(sorted.begin(), sorted.end());
	std::vector<int>::iterator	curr = sorted.begin();
	std::vector<int>::iterator	next = sorted.begin() + 1;

	while (next != sorted.end())
	{
		if (*curr == *next)
			return (true);
		curr++;
		next++;
	}
	return (false);
}

static bool	isSorted(std::vector<int> &vec)
{
	std::vector<int>	sorted(vec);
	std::sort(sorted.begin(), sorted.end());

	return (vec == sorted);
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

static void	printNotSort(PmergeMe &pmerge, std::vector<int> &expected)
{
	std::cerr << "error: not sorted" << std::endl;
	std::cerr << "VECTOR:\t\t";
	printContainer(pmerge.getSortedVector());
	std::cerr << "DEQUE:\t\t";
	printContainer(pmerge.getSortedDeque());
	std::cerr << "EXPECTED:\t";
	printContainer(expected);
}

int	main(int argc, char **argv)
{
	if (!validArgs(argc, argv))
	{
		std::cerr << "Error: invalid arguments" << std::endl;
		std::cerr << "Usage: ./PmergeMe [POSITIVE_INTEGER] [...]" << std::endl;
		return (1);
	}
	argv++;
	std::vector<int>	vec = createContainer<std::vector<int> >(argc - 1, argv);
	std::deque<int>		deq = createContainer<std::deque<int> >(argc - 1, argv);
	if (hasDuplicateNumber(vec))
	{
		std::cerr << "Error: contains duplicate numbers" << std::endl;
		return (1);
	}
	else if (isSorted(vec))
	{
		std::cout << "numbers already sorted" << std::endl;
		return (0);
	}
	std::vector<int>	expectedVector(vec);
	std::deque<int>		expectedDeque(deq);
	std::sort(expectedVector.begin(), expectedVector.end());
	std::sort(expectedDeque.begin(), expectedDeque.end());

	PmergeMe		pmerge(vec, deq);
	std::clock_t	vectorStart = clock();
	pmerge.sort(VECTOR);
	std::clock_t	vectorEnd = clock();
	double vectorTime = double(vectorEnd - vectorStart) / CLOCKS_PER_SEC * 1e3;
	std::clock_t	dequeStart = clock();
	pmerge.sort(DEQUE);
	std::clock_t	dequeEnd = clock();
	double dequeTime = double(dequeEnd - dequeStart) / CLOCKS_PER_SEC * 1e3;

	if (expectedVector != pmerge.getSortedVector() && expectedDeque != pmerge.getSortedDeque())
	{
		printNotSort(pmerge, expectedVector);
		return (1);
	}
	std::cout << "Before:\t";
	printContainer(vec);
	std::cout << "After:\t";
	printContainer(pmerge.getSortedVector());
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : ";
	std::cout << std::fixed << std::setprecision(3) << vectorTime << " ms" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque  : ";
	std::cout << std::fixed << std::setprecision(3) << dequeTime << " ms" << std::endl;
	return (0);
}
