#include "main.hpp"

void printIter(std::map<int, std::string>::iterator &std_it, ft::map<int, std::string>::iterator &ft_it, std::map<int, std::string> &std_m, ft::map<int, std::string> &ft_m)
{
	std::string std_ret;
	std::string ft_ret;

	std_ret = (std_it != std_m.end() ? std_it->second : "not find");
	ft_ret = (ft_it != ft_m.end() ? ft_it->second : "not find");
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
	std::list<std::pair<int, std::string> > std_lst;
	std::list<ft::pair<int, std::string> > ft_lst;

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

	ft::map<int, std::string> ft_m(ft_lst.begin(), ft_lst.end());
	std::map<int, std::string> std_m(std_lst.begin(), std_lst.end());

	ft::map<int, std::string>::iterator ft_it;
	std::map<int, std::string>::iterator std_it;
	// -------------[0]--------------
	printCount(0);
	print(ft_m, std_m);
	// -------------[1]--------------
	// find hi
	printCount(1);
	ft_it = ft_m.find(5);
	std_it = std_m.find(5);
	printIter(std_it, ft_it, std_m, ft_m);

	// -------------[2]--------------
	// 없는 값 find
	printCount(2);
	ft_it = ft_m.find(100);
	std_it = std_m.find(100);
	printIter(std_it, ft_it, std_m, ft_m);
}
