/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:11:48 by revieira          #+#    #+#             */
/*   Updated: 2024/01/30 15:20:44 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool withinLimits(std::string str)
{
	long long	n;
	std::stringstream	ss(str);
	ss >> n;

	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
		return (false);
	return (true);
}

static bool isNumber(const std::string &str)
{
	std::string::const_iterator     it = str.begin();

	if ((*it == '-' || *it == '+') && str.size() > 1)
		it++;
    while (it != str.end() && std::isdigit(*it))
		it++;
	return (!str.empty() && it == str.end() && withinLimits(str));
}

static int	checkOperation(std::string parameter)
{
	std::string validOperations[4] = {
		"+", "-", "*", "/"
	};

	for (int i = 0; i < 4; i++)
		if (parameter == validOperations[i])
			return (i);
	return (-1);
}

static bool isOperation(const std::string &str)
{
	return (checkOperation(str) != -1);
}

static void	execOperation(std::stack<int> &stack, std::string operation)
{
	int	a;
	int	b;

	a = stack.top();
	stack.pop();
	b = stack.top();
	stack.pop();
	switch (checkOperation(operation)) {
		case ADD:
			stack.push(b + a);
			break ;
		case SUB:
			stack.push(b - a);
			break ;
		case MULT:
			stack.push(b * a);
			break ;
		case DIV:
			if (a == 0 && b == 0)
				throw std::runtime_error("Error");
			stack.push(b / a);
			break ;
	}
}

void	rpn(std::string parameters)
{
	std::stack<int>		stack;
	std::stringstream	ss(parameters);
	std::string			word;

	if (parameters.empty())
		throw std::runtime_error("Error");
	while (ss >> word)
	{
		if (isNumber(word))	
			stack.push(std::atoi(word.c_str()));
		else if (isOperation(word) && stack.size() > 1)
			execOperation(stack, word);
		else
			throw std::runtime_error("Error");
	}
	if (stack.size() > 1)
		throw std::runtime_error("Error");
	std::cout << stack.top() << std::endl;
}
