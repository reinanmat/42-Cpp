/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:11:48 by revieira          #+#    #+#             */
/*   Updated: 2024/01/03 18:32:37 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isNumber(const std::string &str)
{
	std::string::const_iterator     it = str.begin();

	if ((*it == '-' || *it == '+') && str.size() > 1)
		it++;
    while (it != str.end() && std::isdigit(*it))
		it++;
	return (!str.empty() && it == str.end());
}

int	checkOperation(std::string word)
{
	std::string validOperations[4] = {
		"+", "-", "*", "/"
	};

	for (int i = 0; i < 4; i++)
		if (word == validOperations[i])
			return (i);
	return (-1);
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
			stack.push(b / a);
			break ;
	}
}

void	rpn(std::string parameters)
{
	std::stack<int>		stack;
	std::stringstream	ss(parameters);
	std::string			word;

	while (ss >> word)
	{
		if (isNumber(word))	
			stack.push(std::atoi(word.c_str()));
		else
			execOperation(stack, word);
	}
	std::cout << stack.top() << std::endl;
}
