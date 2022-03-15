#include "main.hpp"

void retPrint(size_t std_count, size_t ft_count)
{
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << (ft_count ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << (std_count ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_count == std_count ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
}

void count()
{
	testNamePrint("count");
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

	ft::set<std::string> ft_s;
	std::set<std::string> std_s;
	ft_s.insert(ft_lst.begin(), ft_lst.end());
	std_s.insert(std_lst.begin(), std_lst.end());
	//---------------[0]--------------
	printCount(0);
	print(ft_s, std_s);
	size_t std_count, ft_count;
	std::string s;
	
	s = "hi";
	std_count = std_s.count(s);
	ft_count = ft_s.count(s);
	retPrint(std_count, ft_count);
	
	s = "??";
	std_count = std_s.count(s);
	ft_count = ft_s.count(s);
	retPrint(std_count, ft_count);
}
