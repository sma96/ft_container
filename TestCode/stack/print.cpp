#include "main.hpp"

void operatePrint(std::vector<std::string> oper, std::vector<std::string> ft, std::vector<std::string> std)
{
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << "--oper--|------ft------|------std------|---diff--" << std::endl;
	std::cout << ANSI_COLOR_NOMAL;

	for (size_t i = 0; i < oper.size(); i++)
	{
		std::cout << std::setw(4 + oper[i].size() / 2) << oper[i];
		std::cout << ANSI_COLOR_YELLOW;
		std::cout << std::setw(5 - oper[i].size() / 2) << "|";
		std::cout << ANSI_COLOR_NOMAL;

		std::cout << std::setw(7 + ft[i].size() / 2) << ft[i];
		std::cout << ANSI_COLOR_YELLOW;
		std::cout << std::setw(8 - ft[i].size() / 2) << "|";
		std::cout << ANSI_COLOR_NOMAL;

		std::cout << std::setw(7 + std[i].size() / 2) << std[i];
		std::cout << ANSI_COLOR_YELLOW;
		std::cout << std::setw(8 - std[i].size() / 2) << "|";
		std::cout << ANSI_COLOR_NOMAL;

		std::cout << std::setw(11) << (ft[i] == std[i] ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO")
			<< ANSI_COLOR_NOMAL << std::endl;
	}
}

void print(ft::stack<int> ft_s, std::stack<int> std_s)
{
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << "--------ft--------|--------std--------|---diff---" << std::endl;
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << ft_s.size();
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << std_s.size();
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_s.size() == std_s.size() ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;

	while (!ft_s.empty())
	{
		std::cout << std::setw(10) << ft_s.top();
		std::cout << ANSI_COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << ANSI_COLOR_NOMAL;
		std::cout << std::setw(10) << std_s.top();
		std::cout << ANSI_COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << ANSI_COLOR_NOMAL;
		std::cout << std::setw(10) << (ft_s.top() == std_s.top() ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
		ft_s.pop();
		std_s.pop();
	}
}

void print(ft::stack<int, ft::vector<int> > ft_s, std::stack<int, std::vector<int> > std_s)
{
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << "--------ft--------|--------std--------|---diff---" << std::endl;
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << ft_s.size();
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << std_s.size();
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_s.size() == std_s.size() ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;

	while (!ft_s.empty())
	{
		std::cout << std::setw(10) << ft_s.top();
		std::cout << ANSI_COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << ANSI_COLOR_NOMAL;
		std::cout << std::setw(10) << std_s.top();
		std::cout << ANSI_COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << ANSI_COLOR_NOMAL;
		std::cout << std::setw(10) << (ft_s.top() == std_s.top() ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
		ft_s.pop();
		std_s.pop();
	}
}


void testNamePrint(std::string name)
{
	std::cout << ANSI_COLOR_BLUE;
	for (int i = 0; i < 50; i++)
		std::cout << "*";
	std::cout << std::endl;

	std::cout << std::setw(25 + name.size() / 2) << name << std::endl;

	for (int i = 0; i < 50; i++)
		std::cout << "*";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::endl;
}
