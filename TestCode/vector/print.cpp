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

void print(ft::vector<int> &v, std::vector<int> &std_v)
{
	ft::vector<int>::const_iterator it = v.begin();
	ft::vector<int>::const_iterator ite = v.end();
	std::vector<int>::const_iterator std_it = std_v.begin();

	std::cout << ANSI_COLOR_YELLOW;
	std::cout << "--------ft--------|--------std--------|---diff---" << std::endl;
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << v.size();
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << std_v.size();
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(v.size() == std_v.size() ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
	std::cout << std::setw(12) << "capacity : ";
	std::cout << std::setw(3) << v.capacity();
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(12) << "capacity : ";
	std::cout << std::setw(3) << std_v.capacity();
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) << 
		(v.capacity() == std_v.capacity() ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;

	for (; it != ite; it++)
	{
		std::cout << std::setw(10) << *it;
		std::cout << ANSI_COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << ANSI_COLOR_NOMAL;
		std::cout << std::setw(10) << *std_it;
		std::cout << ANSI_COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << ANSI_COLOR_NOMAL;
		std::cout << std::setw(10) << (*it == *std_it ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
		std_it++;
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
