#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

static int	to_upper(unsigned char c)
{
	return (std::toupper(c));
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (EXIT_SUCCESS);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string str(argv[i]);
		std::transform(str.begin(), str.end(), str.begin(), to_upper);
		std::cout << str;
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
