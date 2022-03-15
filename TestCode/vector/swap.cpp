#include "main.hpp"

void swap()
{
	testNamePrint("swap");

	std::vector<int> std_v;
	ft::vector<int> ft_v;
	std::vector<int> std_v2;
	ft::vector<int> ft_v2;

	for (int i = 1; i < 6; i++)
	{
		std_v.push_back(i * 3);
		ft_v.push_back(i * 3);
	}

	for (int i = 1; i < 3; i++)
	{
		std_v2.push_back(i * 5);
		ft_v2.push_back(i * 5);
	}


	print(ft_v, std_v);
	print(ft_v2, std_v2);

	std_v.swap(std_v2);
	ft_v.swap(ft_v2);

	print(ft_v, std_v);
	print(ft_v2, std_v2);

	std::swap(std_v, std_v2);
	ft::swap(ft_v, ft_v2);

	print(ft_v, std_v);
	print(ft_v2, std_v2);
}
