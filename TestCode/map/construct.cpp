#include "main.hpp"

void construct()
{
	testNamePrint("construct");
	std::list<std::pair<int, std::string> > std_lst;
	std::list<ft::pair<int, std::string> > ft_lst;

	std_lst.push_back(std::make_pair<int, std::string>(2, "world"));
	std_lst.push_back(std::make_pair<int, std::string>(1, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "hi"));
	std_lst.push_back(std::make_pair<int, std::string>(10, "my"));
	std_lst.push_back(std::make_pair<int, std::string>(23, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(20, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "name"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));

	ft_lst.push_back(ft::make_pair<int, std::string>(2, "world"));
	ft_lst.push_back(ft::make_pair<int, std::string>(1, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "hi"));
	ft_lst.push_back(ft::make_pair<int, std::string>(10, "my"));
	ft_lst.push_back(ft::make_pair<int, std::string>(23, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(20, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "name"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));

	// ------------------- [0] ----------------------------------
	printCount(0);
	std::map<int, std::string> std_m(std_lst.begin(), std_lst.end());
	ft::map<int, std::string> ft_m(ft_lst.begin(), ft_lst.end());
	print(ft_m, std_m);

	// ------------------- [1] ----------------------------------
	std::map<int, std::string> std_m2(std_m);
	ft::map<int, std::string> ft_m2(ft_m);

	printCount(1);
	print(ft_m2, std_m2);

	// ------------------- [2] ----------------------------------
	std_m2 = std_m;
	ft_m2 = ft_m;

	printCount(2);
	print(ft_m2, std_m2);
}
