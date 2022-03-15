#include "main.hpp"

void construct()
{
	std::pair<int, int> std_p;
	ft::pair<int, int> ft_p;
	print(ft_p, std_p);
	
	std::pair<int, int> std_p2(2, 3);
	ft::pair<int, int> ft_p2(2, 3);
	print(ft_p2, std_p2);

	std::pair<int, int> std_p3;
	ft::pair<int, int> ft_p3;
	std_p3 = std_p2;
	ft_p3 = ft_p2;
	print(ft_p3, std_p3);

	std::pair<int, int> std_p4(std_p3);
	ft::pair<int, int> ft_p4(ft_p3);
	print(ft_p4, std_p4);

	std::pair<int, int> std_p5 = std::make_pair(5, 6);
	ft::pair<int, int> ft_p5 = ft::make_pair(5, 6);
	print(ft_p5, std_p5);
}
