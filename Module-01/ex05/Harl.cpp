/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:53:05 by revieira          #+#    #+#             */
/*   Updated: 2023/10/04 19:59:53 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]: I love having extra bacon for my" <<
		" 7XL-double-cheese-triple-pickle-specialketchup" <<
		" burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "[INFO]: I cannot believe adding extra" <<
		" bacon costs more money. You didn’t put" << 
 		" enough bacon in my burger! If you did," <<
		" I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING] This is unacceptable! I want to" <<
		" speak to the manager now." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]: This is unacceptable!" <<
		" I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*functptr[]) (void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functptr[i])();
			return ;
		}
	}
	std::cout << "Error: harl " << level << " not known" << std::endl;
}
