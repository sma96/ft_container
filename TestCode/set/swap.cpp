#include "main.hpp"

void swap()
{
	testNamePrint("swap");
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

	std::set<int> std_s(std_lst.begin(), std_lst.end());
	ft::set<int> ft_s(ft_lst.begin(), ft_lst.end());
	std::set<int> std_s2(std_lst.begin(), ++(++std_lst.begin()));
	ft::set<int> ft_s2(ft_lst.begin(), ++(++ft_lst.begin()));

	// ------------------[0]--------------
	printCount(0);
	std::cout << std::setw(38) << "---------1번 맵----------" << std::endl;
	print(ft_s, std_s);
	std::cout << std::setw(38) << "---------2번 맵----------" << std::endl;
	print(ft_s2, std_s2);

	// ------------------[1]--------------
	printCount(1);
	std_s.swap(std_s2);
	ft_s.swap(ft_s2);
	std::cout << std::setw(37) << "---------swap 후---------" << std::endl;
	std::cout << std::setw(38) << "---------1번 맵----------" << std::endl;
	print(ft_s, std_s);
	std::cout << std::setw(38) << "---------2번 맵----------" << std::endl;
	print(ft_s2, std_s2);
}
