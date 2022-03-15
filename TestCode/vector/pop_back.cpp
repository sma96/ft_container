#include "main.hpp"

void pop_back()
{
	testNamePrint("pop_back");

	std::vector<int> std_v(3);
	ft::vector<int> ft_v(3);
	
	for (size_t i = 0; i < ft_v.size(); i++)
	{
		std_v[i] = (i + 1) * 3;
		ft_v[i] = (i + 1) * 3;
	}

	print(ft_v, std_v);
	ft_v.pop_back();
	std_v.pop_back();


	print(ft_v, std_v);
	ft_v.pop_back();
	std_v.pop_back();


	print(ft_v, std_v);
	ft_v.pop_back();
	std_v.pop_back();
}
