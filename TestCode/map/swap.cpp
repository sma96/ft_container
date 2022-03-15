#include "main.hpp"

void swap()
{
	testNamePrint("swap");
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

	std::map<int, std::string> std_m(std_lst.begin(), std_lst.end());
	ft::map<int, std::string> ft_m(ft_lst.begin(), ft_lst.end());
	std::map<int, std::string> std_m2(std_lst.begin(), ++(++std_lst.begin()));
	ft::map<int, std::string> ft_m2(ft_lst.begin(), ++(++ft_lst.begin()));

	// ------------------[0]--------------
	printCount(0);
	std::cout << std::setw(38) << "---------1번 맵----------" << std::endl;
	print(ft_m, std_m);
	std::cout << std::setw(38) << "---------2번 맵----------" << std::endl;
	print(ft_m2, std_m2);

	// ------------------[1]--------------
	printCount(1);
	std_m.swap(std_m2);
	ft_m.swap(ft_m2);
	std::cout << std::setw(37) << "---------swap 후---------" << std::endl;
	std::cout << std::setw(38) << "---------1번 맵----------" << std::endl;
	print(ft_m, std_m);
	std::cout << std::setw(38) << "---------2번 맵----------" << std::endl;
	print(ft_m2, std_m2);
}
