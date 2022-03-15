#include "main.hpp"

void clear()
{
	testNamePrint("clear");
	std::list<int> std_lst;
	std::list<int> ft_lst;

	std_lst.push_back(2);
	std_lst.push_back(1);
	std_lst.push_back(5);
	std_lst.push_back(10);
	std_lst.push_back(23);
	std_lst.push_back(20);
	std_lst.push_back(15);
	std_lst.push_back(22);

	ft_lst.push_back(2);
	ft_lst.push_back(1);
	ft_lst.push_back(5);
	ft_lst.push_back(10);
	ft_lst.push_back(23);
	ft_lst.push_back(20);
	ft_lst.push_back(15);
	ft_lst.push_back(22);

	std::set<int> std_s(std_lst.begin(), std_lst.end());
	ft::set<int> ft_s(ft_lst.begin(), ft_lst.end());
	// --------------[0]-------------
	printCount(0);
	print(ft_s, std_s);
	// --------------[1]-------------
	printCount(1);
	std_s.clear();
	ft_s.clear();
	print(ft_s, std_s);
}
