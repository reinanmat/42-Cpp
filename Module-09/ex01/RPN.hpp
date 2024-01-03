/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:35:12 by revieira          #+#    #+#             */
/*   Updated: 2024/01/03 18:04:43 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

#define ADD 0
#define SUB 1
#define MULT 2
#define DIV 3

bool	isNumber(const std::string &str);
int		checkOperation(std::string word);
void	rpn(std::string parameters);
