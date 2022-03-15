#include "main.hpp"
#include <exception>
void at()
{
	testNamePrint("at");

	std::vector<int> std_v(5);
	ft::vector<int> ft_v(5);

	for (size_t i = 0; i < ft_v.size(); i++)
	{
		std_v[i] = (i + 1) * 3;
		ft_v[i] = (i + 1) * 3;
	}

	print(ft_v, std_v);

	try
	{
		std::cout << std::endl;
		std::cout << std::setw(10) << ft_v.at(1);
		std::cout << std::setw(10) << " | ";
		std::cout << std::setw(10) << std_v.at(1);
		std::cout << std::setw(10) << " | ";
		std::cout << std::setw(5) << (ft_v.at(1) == std_v.at(1) ? "OK" : "KO") << std::endl;

		ft_v.at(5);
	}
	catch (const std::exception& oor)
	{
		std::cout << "Out of Range error : " << oor.what() << std::endl;
	}

	try
	{
		std_v.at(5);
	}
	catch (const std::out_of_range& oor)
	{
		std::cout << "Out of Range error : " << oor.what() << std::endl;
	}

}
