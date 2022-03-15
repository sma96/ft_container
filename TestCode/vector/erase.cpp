#include "main.hpp"

void erase()
{
	testNamePrint("erase");

	std::vector<int> std_v;
	ft::vector<int> ft_v;

	for (int i = 1; i < 8; i++)
	{
		std_v.push_back(i * 3);
		ft_v.push_back(i * 3);
	}
	print(ft_v, std_v);

	std_v.erase(std_v.begin());
	ft_v.erase(ft_v.begin());
	print(ft_v, std_v);

	std_v.erase(std_v.end() - 1);
	ft_v.erase(ft_v.end() - 1);
	print(ft_v, std_v);

	std_v.erase(std_v.begin() + 2);
	ft_v.erase(ft_v.begin() + 2);
	print(ft_v, std_v);

	std_v.erase(std_v.begin(), std_v.end());
	ft_v.erase(ft_v.begin(), ft_v.end());
	print(ft_v, std_v);
}
