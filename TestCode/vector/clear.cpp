#include "main.hpp"

void clear()
{
	testNamePrint("clear");

	std::vector<int> std_v;
	ft::vector<int> ft_v;

	for (int i = 0; i < 6; i++)
	{
		std_v.push_back(i * 3);
		ft_v.push_back(i * 3);
	}

	print(ft_v, std_v);

	ft_v.clear();
	std_v.clear();
	print(ft_v, std_v);
}
