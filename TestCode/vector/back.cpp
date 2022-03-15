#include "main.hpp"

void back()
{
	testNamePrint("back");

	std::vector<int>	std_v(3);
	ft::vector<int>		ft_v(3);

	for (size_t i = 0; i < ft_v.size(); i++)
	{
		std_v[i] = (i + 1) * 3;
		ft_v[i] = (i + 1) * 3;
	}
	
	print(ft_v, std_v);
	std::cout << std::setw(27) << "back" << std::endl;
	std::cout << std::setw(10) << ft_v.back();
	std::cout << std::setw(10) << " | ";
	std::cout << std::setw(10) << std_v.back();
	std::cout << std::setw(10) << " | ";
	std::cout << std::setw(5) << (ft_v.back() == std_v.back() ? "OK" : "KO") << std::endl;

	ft_v.erase(ft_v.end() - 1);
	std_v.erase(std_v.end() - 1);

	print(ft_v, std_v);
	std::cout << std::setw(27) << "back" << std::endl;
	std::cout << std::setw(10) << ft_v.back();
	std::cout << std::setw(10) << " | ";
	std::cout << std::setw(10) << std_v.back();
	std::cout << std::setw(10) << " | ";
	std::cout << std::setw(5) << (ft_v.back() == std_v.back() ? "OK" : "KO") << std::endl;

	ft_v.push_back(100);
	std_v.push_back(100);

	print(ft_v, std_v);
	std::cout << std::setw(27) << "back" << std::endl;
	std::cout << std::setw(10) << ft_v.back();
	std::cout << std::setw(10) << " | ";
	std::cout << std::setw(10) << std_v.back();
	std::cout << std::setw(10) << " | ";
	std::cout << std::setw(5) << (ft_v.back() == std_v.back() ? "OK" : "KO") << std::endl;
}
