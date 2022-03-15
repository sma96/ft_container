#include "main.hpp"

void push_back()
{

	testNamePrint("push_back");

	std::vector<int> std_v;
	ft::vector<int> ft_v;

	std_v.push_back(1);
	std_v.push_back(2);
	std_v.push_back(3);
	std_v.push_back(4);
	std_v.push_back(5);
	std_v.push_back(6);
	std_v.push_back(7);
	std_v.push_back(8);
	std_v.push_back(9);

	ft_v.push_back(1);
	ft_v.push_back(2);
	ft_v.push_back(3);
	ft_v.push_back(4);
	ft_v.push_back(5);
	ft_v.push_back(6);
	ft_v.push_back(7);
	ft_v.push_back(8);
	ft_v.push_back(9);

	print(ft_v, std_v);
}
