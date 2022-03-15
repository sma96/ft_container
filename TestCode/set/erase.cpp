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
	std::list<int> std_lst;
	std::list<int> ft_lst;

	std_lst.push_back(2);
	std_lst.push_back(0);
	std_lst.push_back(5);
	std_lst.push_back(10);
	std_lst.push_back(23);
	std_lst.push_back(20);
	std_lst.push_back(15);
	std_lst.push_back(22);

	ft_lst.push_back(2);
	ft_lst.push_back(0);
	ft_lst.push_back(5);
	ft_lst.push_back(10);
	ft_lst.push_back(23);
	ft_lst.push_back(20);
	ft_lst.push_back(15);
	ft_lst.push_back(22);

	std::set<int> std_s(std_lst.begin(), std_lst.end());
	ft::set<int> ft_s(ft_lst.begin(), ft_lst.end());

	// ----------------[0]---------------------
	printCount(0);
	print(ft_s, std_s);

	// ----------------[1]---------------------
	// hello 삭제
	printCount(1);
	std_s.erase(std_s.begin());
	ft_s.erase(ft_s.begin());
	print(ft_s, std_s);

	// ----------------[2]---------------------
	// tester 삭제
	printCount(2);
	std_s.erase(--std_s.end());
	ft_s.erase(--ft_s.end());
	print(ft_s, std_s);

	// ----------------[3]---------------------
	// name 삭제
	printCount(3);
	std_s.erase(++(++(++std_s.begin())));
	ft_s.erase(++(++(++ft_s.begin())));
	print(ft_s, std_s);

	// ----------------[4]---------------------
	// my 삭제
	size_t std_ret;
	size_t ft_ret;
	printCount(4);
	std_ret = std_s.erase(10);
	ft_ret = ft_s.erase(10);
	print(ft_s, std_s);
	retPrint(std_ret, ft_ret);

	// ----------------[5]---------------------
	// 없는 key 삭제
	printCount(5);
	std_ret = std_s.erase(100);
	ft_ret = ft_s.erase(100);
	print(ft_s, std_s);
	retPrint(std_ret, ft_ret);

	// ----------------[6]---------------------
	// 없는 key 삭제
	printCount(6);
	std_ret = std_s.erase(100);
	ft_ret = ft_s.erase(100);
	print(ft_s, std_s);
	retPrint(std_ret, ft_ret);

	// ----------------[7]---------------------
	// 전체 삭제
	printCount(7);
	std_s.erase(std_s.begin(), std_s.end());
	ft_s.erase(ft_s.begin(), ft_s.end());
	print(ft_s, std_s);
}
