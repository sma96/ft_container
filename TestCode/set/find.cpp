#include "main.hpp"

void printIter(std::set<std::string>::iterator &std_it, ft::set<std::string>::iterator &ft_it, std::set<std::string> &std_s, ft::set<std::string> &ft_s)
{
	std::string std_ret;
	std::string ft_ret;

	std_ret = (std_it != std_s.end() ? *std_it : "not find");
	ft_ret = (ft_it != ft_s.end() ? *ft_it : "not find");
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << ft_ret;
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << std_ret;
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(std_ret == ft_ret ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
}

void find()
{
	testNamePrint("find");
	std::list<std::string> std_lst;
	std::list<std::string> ft_lst;

	std_lst.push_back("world");
	std_lst.push_back("hello");
	std_lst.push_back("hi");
	std_lst.push_back("my");
	std_lst.push_back("tester");
	std_lst.push_back("is");
	std_lst.push_back("name");
	std_lst.push_back("map");

	ft_lst.push_back("world");
	ft_lst.push_back("hello");
	ft_lst.push_back("hi");
	ft_lst.push_back("my");
	ft_lst.push_back("tester");
	ft_lst.push_back("is");
	ft_lst.push_back("name");
	ft_lst.push_back("map");

	ft::set<std::string> ft_s(ft_lst.begin(), ft_lst.end());
	std::set<std::string> std_s(std_lst.begin(), std_lst.end());

	ft::set<std::string>::iterator ft_it;
	std::set<std::string>::iterator std_it;

	std::string s;
	// -------------[0]--------------
	printCount(0);
	print(ft_s, std_s);
	// -------------[1]--------------
	// find hi
	printCount(1);
	s = "hi";
	ft_it = ft_s.find(s);
	std_it = std_s.find(s);
	printIter(std_it, ft_it, std_s, ft_s);

	// -------------[2]--------------
	// 없는 값 find
	printCount(2);
	s = "??";
	ft_it = ft_s.find(s);
	std_it = std_s.find(s);
	printIter(std_it, ft_it, std_s, ft_s);
}
