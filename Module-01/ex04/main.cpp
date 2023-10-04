/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:39:49 by revieira          #+#    #+#             */
/*   Updated: 2023/10/04 16:39:21 by revieira         ###   ########.fr       */
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

std::string	searchAndReplace(std::string& str, std::string s1, std::string s2)
{
	int		pos;
	size_t	found;
	std::string	replaced;

	int i = 0;
	pos = 0;
	while ()
	{
		found = str.find(&s1[i], pos);
		if (found != std::string::npos) 
		{
			replaced = str.substr(0, pos);
			replaced = replaced + s2;
		}
		std::cout << str[
	}
	std::cout << pos << std::endl;
	return (replaced);
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
	std::cout << content;
	searchAndReplace(content, argv[2], argv[3]);
	
	file.close();
	
	return (0);
}
