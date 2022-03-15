#include "main.hpp"

void construct()
{
	testNamePrint("construct");

	std::stack<int> std_s;
	ft::stack<int> ft_s;

	for (size_t i = 1; i < 5; i++)
	{
		ft_s.push(i);
		std_s.push(i);
	}

	print(ft_s, std_s);

	std::vector<int> std_v;
	ft::vector<int> ft_v;

	for (size_t i = 1; i < 5; i++)
	{
		std_v.push_back(i * 2);
		ft_v.push_back(i * 2);
	}
  
	std::stack<int, std::vector<int> > std_s2(std_v);
	ft::stack<int, ft::vector<int> > ft_s2(ft_v);

	print(ft_s2, std_s2);
}
