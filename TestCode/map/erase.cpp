#include "main.hpp"

void retPrint(int std_ret, int ft_ret)
{
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << (ft_ret ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << (std_ret ? "TRUE" : "FALSE");
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(ft_ret == std_ret ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
}

void erase()
{
	testNamePrint("erase");
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

	std::map<int, std::string> std_m(std_lst.begin(), std_lst.end());
	ft::map<int, std::string> ft_m(ft_lst.begin(), ft_lst.end());

	// ----------------[0]---------------------
	printCount(0);
	print(ft_m, std_m);

	// ----------------[1]---------------------
	// hello 삭제
	printCount(1);
	std_m.erase(std_m.begin());
	ft_m.erase(ft_m.begin());
	print(ft_m, std_m);

	// ----------------[2]---------------------
	// tester 삭제
	printCount(2);
	std_m.erase(--std_m.end());
	ft_m.erase(--ft_m.end());
	print(ft_m, std_m);

	// ----------------[3]---------------------
	// name 삭제
	printCount(3);
	std_m.erase(++(++(++std_m.begin())));
	ft_m.erase(++(++(++ft_m.begin())));
	print(ft_m, std_m);

	// ----------------[4]---------------------
	// my 삭제
	size_t std_ret;
	size_t ft_ret;
	printCount(4);
	std_ret = std_m.erase(10);
	ft_ret = ft_m.erase(10);
	print(ft_m, std_m);
	retPrint(std_ret, ft_ret);

	// ----------------[5]---------------------
	// 없는 key 삭제
	printCount(5);
	std_ret = std_m.erase(100);
	ft_ret = ft_m.erase(100);
	print(ft_m, std_m);
	retPrint(std_ret, ft_ret);

	// ----------------[6]---------------------
	// 없는 key 삭제
	printCount(6);
	std_ret = std_m.erase(100);
	ft_ret = ft_m.erase(100);
	print(ft_m, std_m);
	retPrint(std_ret, ft_ret);

	// ----------------[7]---------------------
	// 전체 삭제
	printCount(7);
	std_m.erase(std_m.begin(), std_m.end());
	ft_m.erase(ft_m.begin(), ft_m.end());
	print(ft_m, std_m);
}
