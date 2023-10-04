/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:39:49 by revieira          #+#    #+#             */
/*   Updated: 2023/10/04 18:44:50 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <fstream>
#include <string>

std::string	getFileContent(std::string filename)
{
	std::ifstream	file;
	std::string		content;

	file.open(filename.c_str(), std::ifstream::in);
	getline(file, content, '\0');
	file.close();
	content = content + '\0';
	return (content);
}

void	writeAndReplace(std::ofstream& fd, std::string& str, std::string s1, std::string s2)
{
	size_t	stringSize;
	size_t	replaceSize;
	
	stringSize = str.size();
	replaceSize = s1.size();
	for (size_t i = 0; i < stringSize; i++)
	{
		if (i + replaceSize <= stringSize && str.substr(i, replaceSize).compare(s1) == 0)
		{
			fd << s2;
			i += replaceSize;
		}
		fd << str[i];
	}
}

void	toReplace(std::string originalFilename, std::string s1, std::string s2)
{
	std::string		content;
	std::string		replacedFilename;

	content = getFileContent(originalFilename);
	replacedFilename = originalFilename.append(".replace");
	std::ofstream	replacedFile(replacedFilename.c_str());
	writeAndReplace(replacedFile, content, s1, s2);
	replacedFile.close();
}

int	validArgs(int argc, char **argv)
{
	std::ifstream	file;
	if (argc != 4)
	{
		std::cout << "Error: Invalid parameters" << std::endl;
		std::cout << "Usage: <FILE> <REPLACE> <TO_REPLACE>" << std::endl;
		return (0);
	}
	file.open(argv[1], std::ifstream::in);
	if (!file.is_open())
	{
		std::cout << "No such file or directory" << std::endl;
		return (0);
	}
	file.close();
	return (1);
}

int	main(int argc, char **argv)
{
	if (!validArgs(argc, argv))
		return (1);
	toReplace(argv[1], argv[2], argv[3]);
	return (0);
}
