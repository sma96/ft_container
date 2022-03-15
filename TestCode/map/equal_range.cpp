#include "main.hpp"

static void printIter(std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> &std_pr, ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> &ft_pr,
		std::map<int, std::string> &std_m, ft::map<int, std::string> &ft_m)
{
	std::string std_ret;
	std::string ft_ret;

	std_ret = (std_pr.first != std_m.end() ? std_pr.first->second : "not find");
	ft_ret = (ft_pr.first != ft_m.end() ? ft_pr.first->second : "not find");
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


	std_ret = (std_pr.second != std_m.end() ? std_pr.second->second : "not find");
	ft_ret = (ft_pr.second != ft_m.end() ? ft_pr.second->second : "not find");
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
	std::list<std::pair<int, std::string> > std_lst;
	std::list<ft::pair<int, std::string> > ft_lst;
	std::map<int, std::string> std_m;
	ft::map<int, std::string> ft_m;
	std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator> std_pr;
	ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> ft_pr;

	std_lst.push_back(std::make_pair<int, std::string>(2, "world"));
	std_lst.push_back(std::make_pair<int, std::string>(0, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "hi"));
	std_lst.push_back(std::make_pair<int, std::string>(10, "my"));
	std_lst.push_back(std::make_pair<int, std::string>(23, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(20, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "name"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));

	ft_lst.push_back(ft::make_pair<int, std::string>(2, "world"));
	ft_lst.push_back(ft::make_pair<int, std::string>(0, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "hi"));
	ft_lst.push_back(ft::make_pair<int, std::string>(10, "my"));
	ft_lst.push_back(ft::make_pair<int, std::string>(23, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(20, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "name"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));

	ft_m.insert(ft_lst.begin(), ft_lst.end());
	std_m.insert(std_lst.begin(), std_lst.end());

	// -----------[0]------------
	printCount(0);
	print(ft_m, std_m);
	
	// -----------[1]------------
	// 최하 미만
	printCount(1);
	std_pr = std_m.equal_range(-1);
	ft_pr = ft_m.equal_range(-1);
	printIter(std_pr, ft_pr, std_m, ft_m);
	
	// -----------[2]------------
	// 최하
	printCount(2);
	std_pr = std_m.equal_range(0);
	ft_pr = ft_m.equal_range(0);
	printIter(std_pr, ft_pr, std_m, ft_m);
	
	// -----------[3]------------
	// 중간
	printCount(3);
	std_pr = std_m.equal_range(15);
	ft_pr = ft_m.equal_range(15);
	printIter(std_pr, ft_pr, std_m, ft_m);
	
	// -----------[4]------------
	// 최대
	printCount(4);
	std_pr = std_m.equal_range(23);
	ft_pr = ft_m.equal_range(23);
	printIter(std_pr, ft_pr, std_m, ft_m);
	
	// -----------[5]------------
	// 최대 초과
	printCount(5);
	std_pr = std_m.equal_range(100);
	ft_pr = ft_m.equal_range(100);
	printIter(std_pr, ft_pr, std_m, ft_m);

}
