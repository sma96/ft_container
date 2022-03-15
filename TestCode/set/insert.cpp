#include "main.hpp"

void retPrint(std::pair<std::set<int>::iterator, bool> &std_ret, ft::pair<ft::set<int>::iterator, bool> &ft_ret)
{
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << *(ft_ret.first);
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << *(std_ret.first);
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(*(ft_ret.first) == *(std_ret.first) ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;

	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << (ft_ret.second ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << (std_ret.second ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_ret.second == std_ret.second ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
}

void retPrint2(std::set<int>::iterator std_it, ft::set<int>::iterator ft_it)
{
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << *(ft_it);
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << *(std_it);
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(*ft_it == *std_it ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
}

void insert()
{
	testNamePrint("insert");
	std::pair<std::set<int>::iterator, bool> std_ret;
	ft::pair<ft::set<int>::iterator, bool> ft_ret;

	std::set<int>::iterator std_it;
	ft::set<int>::iterator ft_it;

	std::set<int> std_s;
	ft::set<int> ft_s;

	// ------------------[0]--------------
	std_ret = std_s.insert(0);
	ft_ret = ft_s.insert(0);

	printCount(0);
	print(ft_s, std_s);
	retPrint(std_ret, ft_ret);

	// ------------------[1]--------------
	std_ret = std_s.insert(0);
	ft_ret = ft_s.insert(0);

	printCount(1);
	print(ft_s, std_s);
	retPrint(std_ret, ft_ret);

	// ------------------[2]--------------
	std_it = std_s.insert(std_s.begin(), 3);
	ft_it = ft_s.insert(ft_s.begin(), 3);

	printCount(2);
	print(ft_s, std_s);
	retPrint2(std_it, ft_it);

	// ------------------[3]--------------
	std_it = std_s.insert(std_s.begin(), 3);
	ft_it = ft_s.insert(ft_s.begin(), 3);

	printCount(3);
	print(ft_s, std_s);
	retPrint2(std_it, ft_it);

	// ------------------[4]--------------
	printCount(4);
	std::list<int> std_lst;
	std::list<int> ft_lst;

	std_lst.push_back(2);
	std_lst.push_back(0);
	std_lst.push_back(5);
	std_lst.push_back(10);
	std_lst.push_back(23);
	std_lst.push_back(20);
	std_lst.push_back(15);
	std_lst.push_back(22);

	ft_lst.push_back(2);
	ft_lst.push_back(0);
	ft_lst.push_back(5);
	ft_lst.push_back(10);
	ft_lst.push_back(23);
	ft_lst.push_back(20);
	ft_lst.push_back(15);
	ft_lst.push_back(22);

	ft_s.insert(ft_lst.begin(), ft_lst.end());
	std_s.insert(std_lst.begin(), std_lst.end());
	print(ft_s, std_s);
}
