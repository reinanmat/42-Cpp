/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:39:49 by revieira          #+#    #+#             */
/*   Updated: 2023/10/04 17:18:29 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string	getFileContent(std::ifstream& filename)
{
	std::string	content;

	getline(filename, content, '\0');
	content = content + '\0';
	return (content);
}

void	searchAndReplace(std::string& str, std::string s1, std::string s2)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str.substr(i, s1.size()).compare(s1) == 0)
		{
			std::cout << s2;
			i += s1.size();
		}
		std::cout << str[i];
	}
}

int	main(int argc, char **argv)
{
	
	if (argc != 4)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	std::ifstream	file(argv[1]);

	if (!file.is_open())
	{
		std::cout << "Error 2" << std::endl;
		return (1);
	}

	std::string	content = getFileContent(file);
	std::cout << "========>Texto orginal:" << std::endl;
	std::cout << content;
	std::cout << "\n=======>Texto modificado:" << std::endl;
	searchAndReplace(content, argv[2], argv[3]);
	
	file.close();
	
	return (0);
}
