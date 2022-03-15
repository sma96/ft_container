#include "main.hpp"

void resize()
{
	testNamePrint("resize");
	std::vector<int> std_v(5);
	ft::vector<int> ft_v(5);

	for (size_t i = 0; i < ft_v.size(); i++)
	{
		std_v[i] = i * 3;
		ft_v[i] = i * 3;
	}
	print(ft_v, std_v);

	std_v.resize(10);
	ft_v.resize(10);
	print(ft_v, std_v);

	std_v.resize(3, 2);
	ft_v.resize(3, 2);
	print(ft_v, std_v);

	std_v.resize(5, 5);
	ft_v.resize(5, 5);
	print(ft_v, std_v);
}
