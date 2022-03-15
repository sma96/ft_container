#include "main.hpp"

void retPrint(std::pair<std::map<int, std::string>::iterator, bool> &std_ret, ft::pair<ft::map<int, std::string>::iterator, bool> &ft_ret)
{
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << ft_ret.first->second;
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << std_ret.first->second;
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_ret.first->second == std_ret.first->second ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;

	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << (ft_ret.second ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << (std_ret.second ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_ret.second == std_ret.second ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
}

void retPrint2(std::map<int, std::string>::iterator std_it, ft::map<int, std::string>::iterator ft_it)
{
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << ft_it->second;
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << std_it->second;
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_it->second == std_it->second ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
}

void insert()
{
	testNamePrint("insert");
	std::pair<std::map<int, std::string>::iterator, bool> std_ret;
	ft::pair<ft::map<int, std::string>::iterator, bool> ft_ret;

	std::map<int, std::string>::iterator std_it;
	ft::map<int, std::string>::iterator ft_it;

	std::map<int, std::string> std_m;
	ft::map<int, std::string> ft_m;

	// ------------------[0]--------------
	std_ret = std_m.insert(std::make_pair<int, std::string>(0, "insert"));
	ft_ret = ft_m.insert(ft::make_pair<int, std::string>(0, "insert"));

	printCount(0);
	print(ft_m, std_m);
	retPrint(std_ret, ft_ret);

	// ------------------[1]--------------
	std_ret = std_m.insert(std::make_pair<int, std::string>(0, "insert"));
	ft_ret = ft_m.insert(ft::make_pair<int, std::string>(0, "insert"));

	printCount(1);
	print(ft_m, std_m);
	retPrint(std_ret, ft_ret);

	// ------------------[2]--------------
	std_it = std_m.insert(std_m.begin(), std::make_pair<int, std::string>(3, "insert2"));
	ft_it = ft_m.insert(ft_m.begin(), ft::make_pair<int, std::string>(3, "insert2"));

	printCount(2);
	print(ft_m, std_m);
	retPrint2(std_it, ft_it);

	// ------------------[3]--------------
	std_it = std_m.insert(std_m.begin(), std::make_pair<int, std::string>(3, "insert3"));
	ft_it = ft_m.insert(ft_m.begin(), ft::make_pair<int, std::string>(3, "insert3"));

	printCount(3);
	print(ft_m, std_m);
	retPrint2(std_it, ft_it);

	// ------------------[4]--------------
	printCount(4);
	std::list<std::pair<int, std::string> > std_lst;
	std::list<ft::pair<int, std::string> > ft_lst;

	std_lst.push_back(std::make_pair<int, std::string>(2, "world"));
	std_lst.push_back(std::make_pair<int, std::string>(0, "hello"));
	std_lst.push_back(std::make_pair<int, std::string>(5, "hi"));
	std_lst.push_back(std::make_pair<int, std::string>(10, "my"));
	std_lst.push_back(std::make_pair<int, std::string>(23, "tester"));
	std_lst.push_back(std::make_pair<int, std::string>(20, "is"));
	std_lst.push_back(std::make_pair<int, std::string>(15, "name"));
	std_lst.push_back(std::make_pair<int, std::string>(22, "map"));

	ft_lst.push_back(ft::make_pair<int, std::string>(2, "world"));
	ft_lst.push_back(ft::make_pair<int, std::string>(0, "hello"));
	ft_lst.push_back(ft::make_pair<int, std::string>(5, "hi"));
	ft_lst.push_back(ft::make_pair<int, std::string>(10, "my"));
	ft_lst.push_back(ft::make_pair<int, std::string>(23, "tester"));
	ft_lst.push_back(ft::make_pair<int, std::string>(20, "is"));
	ft_lst.push_back(ft::make_pair<int, std::string>(15, "name"));
	ft_lst.push_back(ft::make_pair<int, std::string>(22, "map"));

	ft_m.insert(ft_lst.begin(), ft_lst.end());
	std_m.insert(std_lst.begin(), std_lst.end());
	print(ft_m, std_m);
}
