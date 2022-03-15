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

	ft::map<int, std::string> ft_m;
	std::map<int, std::string> std_m;
	ft_m.insert(ft_lst.begin(), ft_lst.end());
	std_m.insert(std_lst.begin(), std_lst.end());
	//---------------[0]--------------
	printCount(0);
	print(ft_m, std_m);
	size_t std_count, ft_count;
	
	std_count = std_m.count(5);
	ft_count = ft_m.count(5);
	retPrint(std_count, ft_count);
	
	std_count = std_m.count(100);
	ft_count = ft_m.count(100);
	retPrint(std_count, ft_count);
}
