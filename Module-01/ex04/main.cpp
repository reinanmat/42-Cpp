/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:39:49 by revieira          #+#    #+#             */
/*   Updated: 2023/10/24 19:01:56 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string	getFileContent(std::string filename)
{
	std::ifstream	file;
	std::string		content;

	file.open(filename.c_str(), std::ifstream::in);
	std::getline(file, content, '\0');
	file.close();
	return (content);
}

void	searchAndReplace(std::ofstream& fd, std::string content, std::string s1, std::string s2)
{
	size_t	contentSize;
	size_t	replaceSize;
	
	contentSize = content.size();
	replaceSize = s1.size();
	for (size_t i = 0; i < contentSize; i++)
	{
		if (i + replaceSize <= contentSize && content.compare(i, replaceSize, s1) == 0)
		{
			fd << s2;
			i += replaceSize;
		}
		fd << content[i];
	}
}

void	createReplacedFile(std::string originalFile, std::string s1, std::string s2)
{
	std::string		content;
	std::string		replacedFilename;
	std::ofstream	replacedFile;

	content = getFileContent(originalFile);
	replacedFilename = originalFile.append(".replace");
	replacedFile.open(replacedFilename.c_str());
	if (s1 == s2)
		replacedFile << content;
	else
		searchAndReplace(replacedFile, content, s1, s2);
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
	createReplacedFile(argv[1], argv[2], argv[3]);
	return (0);
}
