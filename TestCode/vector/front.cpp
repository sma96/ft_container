#include "main.hpp"

void front()
{
	testNamePrint("front");

	std::vector<int>	std_v(3);
	ft::vector<int>		ft_v(3);

	for (size_t i = 0; i < ft_v.size(); i++)
	{
		std_v[i] = (i + 1) * 3;
		ft_v[i] = (i + 1) * 3;
	}
	
	print(ft_v, std_v);
	std::cout << std::setw(27) << "front" << std::endl;
	std::cout << std::setw(10) << ft_v.front();
	std::cout << std::setw(10) << " | ";
	std::cout << std::setw(10) << std_v.front();
	std::cout << std::setw(10) << " | ";
	std::cout << std::setw(5) << (ft_v.front() == std_v.front() ? "OK" : "KO") << std::endl;

	ft_v.erase(ft_v.begin());
	std_v.erase(std_v.begin());

	print(ft_v, std_v);
	std::cout << std::setw(27) << "front" << std::endl;
	std::cout << std::setw(10) << ft_v.front();
	std::cout << std::setw(10) << " | ";
	std::cout << std::setw(10) << std_v.front();
	std::cout << std::setw(10) << " | ";
	std::cout << std::setw(5) << (ft_v.front() == std_v.front() ? "OK" : "KO") << std::endl;

	ft_v.insert(ft_v.begin(), 100);
	std_v.insert(std_v.begin(), 100);

	print(ft_v, std_v);
	std::cout << std::setw(27) << "front" << std::endl;
	std::cout << std::setw(10) << ft_v.front();
	std::cout << std::setw(10) << " | ";
	std::cout << std::setw(10) << std_v.front();
	std::cout << std::setw(10) << " | ";
	std::cout << std::setw(5) << (ft_v.front() == std_v.front() ? "OK" : "KO") << std::endl;
}
