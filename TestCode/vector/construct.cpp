#include "main.hpp"

void construct()
{
	testNamePrint("construct");

	std::vector<int> std_v;
	ft::vector<int> ft_v;
	print(ft_v, std_v);

	std::vector<int> std_v2(3);
	ft::vector<int> ft_v2(3);
	print(ft_v2, std_v2);

	std::vector<int> std_v3(std_v2.begin(), std_v2.end());
	ft::vector<int> ft_v3(ft_v2.begin(), ft_v2.end());
	print(ft_v3, std_v3);

	std::vector<int> std_v4(2, 10);
	ft::vector<int> ft_v4(2, 10);
	print(ft_v4, std_v4);

	std::vector<int> std_v5(std_v4);
	ft::vector<int> ft_v5(ft_v4);
	print(ft_v5, std_v5);

	for (int i = 1; i < 3; i++)
	{
		ft_v5.push_back(1);
		std_v5.push_back(1);
	}
	std::vector<int> std_v6;
	ft::vector<int> ft_v6;
	std_v6 = std_v5;
	ft_v6 = ft_v5;
	print(ft_v6, std_v6);
}
