#include <iostream>
#include <cstring>

void	printInUpperCase(std::string str)
{
	for (size_t i = 0; i < str.size(); i++) {
		std::cout << char(toupper(str[i]));
	}
}

int	main(int argc, char **argv)
{
	std::string str;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else { 
		argv++;
		for (int i = 0; i < argc - 1; i++) {
			str = argv[i];
			printInUpperCase(str);
			if (i == argc - 2)
				std::cout << std::endl;
			else
				std::cout << ' ';
		}
	}
	return (0);
}
