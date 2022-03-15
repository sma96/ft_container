#include "main.hpp"

static void printIter(std::pair<std::set<std::string>::iterator, std::set<std::string>::iterator> &std_pr, ft::pair<ft::set<std::string>::iterator, ft::set<std::string>::iterator> &ft_pr,
		std::set<std::string> &std_s, ft::set<std::string> &ft_s)
{
	std::string std_ret;
	std::string ft_ret;

	std_ret = (std_pr.first != std_s.end() ? *std_pr.first : "not find");
	ft_ret = (ft_pr.first != ft_s.end() ? *ft_pr.first : "not find");
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << ft_ret;
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << std_ret;
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_ret == std_ret ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;


	std_ret = (std_pr.second != std_s.end() ? *std_pr.second : "not find");
	ft_ret = (ft_pr.second != ft_s.end() ? *ft_pr.second : "not find");
	std::cout << std::setw(8) << "ret2 : ";
	std::cout << std::setw(7) << ft_ret;
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(8) << "ret2 : ";
	std::cout << std::setw(7) << std_ret;
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_ret == std_ret ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
}

void equal_range()
{
	testNamePrint("equal_range");
	std::list<std::string> std_lst;
	std::list<std::string> ft_lst;
	std::set<std::string> std_s;
	ft::set<std::string> ft_s;
	std::pair<std::set<std::string>::iterator, std::set<std::string>::iterator> std_pr;
	ft::pair<ft::set<std::string>::iterator, ft::set<std::string>::iterator> ft_pr;

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

	ft_s.insert(ft_lst.begin(), ft_lst.end());
	std_s.insert(std_lst.begin(), std_lst.end());
	std::string s;

	// -----------[0]------------
	printCount(0);
	print(ft_s, std_s);
	
	// -----------[1]------------
	// 최하 미만
	s = "a";
	printCount(1);
	std_pr = std_s.equal_range(s);
	ft_pr = ft_s.equal_range(s);
	printIter(std_pr, ft_pr, std_s, ft_s);
	
	// -----------[2]------------
	// 최하
	s = "hi";
	printCount(2);
	std_pr = std_s.equal_range(s);
	ft_pr = ft_s.equal_range(s);
	printIter(std_pr, ft_pr, std_s, ft_s);
	
	// -----------[3]------------
	// 중간
	printCount(3);
	s = "name";
	std_pr = std_s.equal_range(s);
	ft_pr = ft_s.equal_range(s);
	printIter(std_pr, ft_pr, std_s, ft_s);
	
	// -----------[4]------------
	// 최대
	printCount(4);
	s = "world";
	std_pr = std_s.equal_range(s);
	ft_pr = ft_s.equal_range(s);
	printIter(std_pr, ft_pr, std_s, ft_s);
	
	// -----------[5]------------
	// 최대 초과
	printCount(5);
	s = "z";
	std_pr = std_s.equal_range(s);
	ft_pr = ft_s.equal_range(s);
	printIter(std_pr, ft_pr, std_s, ft_s);
}
