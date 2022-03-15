#include "main.hpp"

void insert()
{
	testNamePrint("insert");

	std::vector<int> std_v(3);
	ft::vector<int> ft_v(3);

	std_v.clear();
	ft_v.clear();
	for (size_t i = 1; i < 4; i++)
	{
		std_v.insert(std_v.begin(), i * 3);
		ft_v.insert(ft_v.begin(), i * 3);
		print(ft_v, std_v);
	}

	std_v.insert(std_v.end(), 10);
	ft_v.insert(ft_v.end(), 10);
	print(ft_v, std_v);

	std_v.insert(std_v.begin() + 2, 5);
	ft_v.insert(ft_v.begin() + 2, 5);
	print(ft_v, std_v);

	std_v.insert(std_v.begin(), 2, 0);
	ft_v.insert(ft_v.begin(), 2, 0);
	print(ft_v, std_v);

	std_v.insert(std_v.end(), 3, 20);
	ft_v.insert(ft_v.end(), 3, 20);
	print(ft_v, std_v);

	std_v.insert(std_v.begin() + 5, 15, 20);
	ft_v.insert(ft_v.begin() + 5, 15, 20);
	print(ft_v, std_v);

	std_v.clear();
	ft_v.clear();

	for (int i = 1; i < 4; i++)
	{
		std_v.push_back(i * 3);
		ft_v.push_back(i * 3);
	}

	print(ft_v, std_v);
	std::vector<int> std_v2;
	ft::vector<int> ft_v2;

	std_v2.insert(std_v2.begin(), std_v.begin(), std_v.end());
	ft_v2.insert(ft_v2.begin(), ft_v.begin(), ft_v.end());
	print(ft_v2, std_v2);
	std::cout << "---------------------------sdsssssss--" << std::endl;

	std_v.erase(std_v.begin());
	ft_v.erase(ft_v.begin());

	std_v2.insert(std_v2.end(), std_v.begin(), std_v.end());
	ft_v2.insert(ft_v2.end(), ft_v.begin(), ft_v.end());
	print(ft_v2, std_v2);
}
