#include "main.hpp"

static void printIter(std::set<std::string>::iterator &std_it, ft::set<std::string>::iterator &ft_it, std::set<std::string> &std_s, ft::set<std::string> &ft_s)
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

void bound()
{
	testNamePrint("bound");

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

	std::set<std::string> std_s;
	ft::set<std::string> ft_s;
	std::set<std::string>::iterator std_it;
	ft::set<std::string>::iterator ft_it;
	ft_s.insert(ft_lst.begin(), ft_lst.end());
	std_s.insert(std_lst.begin(), std_lst.end());

	std::string s;
	// -------------[0]-------------
	printCount(0);
	print(ft_s, std_s);
	
	// -------------[1]-------------
	// 제일 적은 값보다 더 작은 값
	printCount(1);
	s = "a";
	std_it = std_s.lower_bound(s);
	ft_it = ft_s.lower_bound(s);
	printIter(std_it, ft_it, std_s, ft_s);

	// -------------[2]-------------
	// 제일 작은 값
	printCount(0);
	s = "hi";
	std_it = std_s.lower_bound(s);
	ft_it = ft_s.lower_bound(s);
	printIter(std_it, ft_it, std_s, ft_s);

	// -------------[3]-------------
	// 중간 값
	printCount(3);
	s = "name";
	std_it = std_s.lower_bound(s);
	ft_it = ft_s.lower_bound(s);
	printIter(std_it, ft_it, std_s, ft_s);

	// -------------[4]-------------
	// 최대 값
	printCount(4);
	s = "world";
	std_it = std_s.lower_bound(s);
	ft_it = ft_s.lower_bound(s);
	printIter(std_it, ft_it, std_s, ft_s);

	// -------------[5]-------------
	// 최대 이상
	printCount(5);
	s = "z";
	std_it = std_s.lower_bound(s);
	ft_it = ft_s.lower_bound(s);
	printIter(std_it, ft_it, std_s, ft_s);


	// -------------[6]-------------
	// 제일 적은 값보다 더 작은 값
	printCount(6);
	s = "a";
	std_it = std_s.upper_bound(s);
	ft_it = ft_s.upper_bound(s);
	printIter(std_it, ft_it, std_s, ft_s);

	// -------------[7]-------------
	// 제일 작은 값
	printCount(7);
	s = "hi";
	std_it = std_s.upper_bound(s);
	ft_it = ft_s.upper_bound(s);
	printIter(std_it, ft_it, std_s, ft_s);

	// -------------[8]-------------
	// 중간 값
	printCount(8);
	s = "name";
	std_it = std_s.upper_bound(s);
	ft_it = ft_s.upper_bound(s);
	printIter(std_it, ft_it, std_s, ft_s);

	// -------------[9]-------------
	// 최대 값
	printCount(9);
	s = "world";
	std_it = std_s.upper_bound(s);
	ft_it = ft_s.upper_bound(s);
	printIter(std_it, ft_it, std_s, ft_s);

	// -------------[10]-------------
	// 최대 값 초과
	printCount(10);
	s = "z";
	std_it = std_s.upper_bound(s);
	ft_it = ft_s.upper_bound(s);
	printIter(std_it, ft_it, std_s, ft_s);


}
