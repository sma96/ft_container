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

void print(ft::map<int, std::string> &ft_m, std::map<int, std::string> &std_m)
{
	ft::map<int, std::string>::const_iterator it = ft_m.begin();
	ft::map<int, std::string>::const_iterator ite = ft_m.end();
	std::map<int, std::string>::const_iterator std_it = std_m.begin();

	std::cout << ANSI_COLOR_YELLOW;
	std::cout << "--------ft--------|--------std--------|---diff---" << std::endl;
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << ft_m.size();
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << std_m.size();
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_m.size() == std_m.size() ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;

	for (; it != ite; it++)
	{
		//-------------- key ---------
//		std::cout << std::setw(10) << it->first;
//		std::cout << ANSI_COLOR_YELLOW;
//		std::cout << std::setw(10) << " | ";
//		std::cout << ANSI_COLOR_NOMAL;
//		std::cout << std::setw(10) << std_it->first;
//		std::cout << ANSI_COLOR_YELLOW;
//		std::cout << std::setw(10) << " | ";
//		std::cout << ANSI_COLOR_NOMAL;
//		std::cout << std::setw(10) << (it->first == std_it->first ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
		//------------- value ----------
		std::cout << std::setw(10) << it->second;
		std::cout << ANSI_COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << ANSI_COLOR_NOMAL;
		std::cout << std::setw(10) << std_it->second;
		std::cout << ANSI_COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << ANSI_COLOR_NOMAL;
		std::cout << std::setw(10) << (it->second == std_it->second ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
		std_it++;

	}
}

void printKey(ft::map<int, std::string> &ft_m, std::map<int, std::string> &std_m)
{
	ft::map<int, std::string>::const_iterator it = ft_m.begin();
	ft::map<int, std::string>::const_iterator ite = ft_m.end();
	std::map<int, std::string>::const_iterator std_it = std_m.begin();

	std::cout << ANSI_COLOR_YELLOW;
	std::cout << "--------ft--------|--------std--------|---diff---" << std::endl;
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << ft_m.size();
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(12) << "size : ";
	std::cout << std::setw(3) << std_m.size();
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_m.size() == std_m.size() ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;

	for (; it != ite; it++)
	{
		//-------------- key ---------
		std::cout << std::setw(10) << it->first;
		std::cout << ANSI_COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << ANSI_COLOR_NOMAL;
		std::cout << std::setw(10) << std_it->first;
		std::cout << ANSI_COLOR_YELLOW;
		std::cout << std::setw(10) << " | ";
		std::cout << ANSI_COLOR_NOMAL;
		std::cout << std::setw(10) << (it->first == std_it->first ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
		std_it++;
	}
}
void printCount(int count)
{
	std::cout << std::setw(24) <<  "[" << count << "]" << std::endl;
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
