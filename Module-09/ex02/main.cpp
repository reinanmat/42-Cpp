/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:21:32 by revieira          #+#    #+#             */
/*   Updated: 2024/01/16 17:21:14 by revieira         ###   ########.fr       */
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

// static void	printArguments(int argc, char **argv)
// {
// 	for (int i = 1; i < argc - 1; i++)
// 		std::cout << argv[i] << " ";
// 	std::cout << argv[argc - 1] << std::endl;
// }
//
// static void	printContainer(const std::vector<int> &vec, const std::list<int> &lst)
// {
// 	std::vector<int>	tmpVec(lst.begin(), lst.end());
// 	std::list<int>		tmpLst(vec.begin(), vec.end());
//
// 	if (!(tmpVec == vec && tmpLst == lst))
// 	{
// 		std::cout << "Error" << std::endl;
// 		return ;
// 	}
// 	std::vector<int>::const_iterator	it;
// 	for (it = vec.begin(); it != vec.end() - 1; it++)
// 		std::cout << *it << " ";
// 	std::cout << *it << std::endl;
// }

int	main(int argc, char **argv)
{

	if (!validArgs(argc, argv))
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	std::vector<int>	vec;
	std::list<int>		lst;
	for (int i = 1; i < argc; i++)
	{
		int num = std::atoi(argv[i]);
		vec.push_back(num);
		lst.push_back(num);
	}

	PmergeMe	pmerge(vec, lst);

	pmerge.sort(VECTOR);
	

	// std::cout << "Before:\t";
	// printArguments(argc, argv);
	// std::cout << "After:\t";
	// printContainer(vec, lst);
	return (0);
}
