#include "main.hpp"

void assign()
{
	testNamePrint("assign");

	std::vector<int> std_v;
	ft::vector<int> ft_v;

	std_v.assign(3, 3);
	ft_v.assign(3, 3);
	print(ft_v, std_v);

	std::vector<int> std_v2(3);
	ft::vector<int> ft_v2(3);

	for (size_t i = 0; i < ft_v2.size(); i++)
	{
		std_v2[i] = (i + 1) * 4;
		ft_v2[i] = (i + 1) * 4;
	}

	print(ft_v2, std_v2);

	std::vector<int> std_v3;
	ft::vector<int> ft_v3;

	std_v3.assign(std_v2.begin(), std_v2.end());
	ft_v3.assign(ft_v2.begin(), ft_v2.end());

	print(ft_v3, std_v3);

	std_v3.assign(std_v.begin(), std_v.end());
	ft_v3.assign(ft_v.begin(), ft_v.end());
	print(ft_v3, std_v3);
	////////////
	// 안 비어있는 벡터에 assign하기
}
