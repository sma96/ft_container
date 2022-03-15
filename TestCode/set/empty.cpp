#include "main.hpp"

void empty()
{
	testNamePrint("empty");
	std::set<int> std_s;
	ft::set<int> ft_s;

	// --------------[0]----------------
	printCount(0);
	print(ft_s, std_s);
	std::cout << std::setw(10) << (ft_s.empty() == 0 ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(11) << (std_s.empty() == 0 ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(11) << (ft_s.empty() == std_s.empty() ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;

	// --------------[1]----------------
	std_s.insert(1);
	ft_s.insert(1);
	printCount(1);
	print(ft_s, std_s);
	std::cout << std::setw(10) << (ft_s.empty() == 0 ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(11) << (std_s.empty() == 0 ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(11) << (ft_s.empty() == std_s.empty() ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;

	// --------------[0]----------------
	std_s.clear();
	ft_s.clear();
	printCount(0);
	print(ft_s, std_s);
	std::cout << std::setw(10) << (ft_s.empty() == 0 ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(11) << (std_s.empty() == 0 ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(9) << "|";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(11) << (ft_s.empty() == std_s.empty() ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
}
