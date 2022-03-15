#include "main.hpp"

void empty()
{
	testNamePrint("empty");
	std::map<int, std::string> std_m;
	ft::map<int, std::string> ft_m;

	// --------------[0]----------------
	printCount(0);
	print(ft_m, std_m);
	std::cout << std::setw(10) << (ft_m.empty() == 0 ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(11) << (std_m.empty() == 0 ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(11) << (ft_m.empty() == std_m.empty() ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;

	// --------------[1]----------------
	std_m[1] = "hi";
	ft_m[1] = "hi";
	printCount(1);
	print(ft_m, std_m);
	std::cout << std::setw(10) << (ft_m.empty() == 0 ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(11) << (std_m.empty() == 0 ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(11) << (ft_m.empty() == std_m.empty() ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;

	// --------------[0]----------------
	std_m.clear();
	ft_m.clear();
	printCount(0);
	print(ft_m, std_m);
	std::cout << std::setw(10) << (ft_m.empty() == 0 ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(11) << (std_m.empty() == 0 ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(11) << (ft_m.empty() == std_m.empty() ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
}
