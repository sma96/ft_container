#include "main.hpp"

void operTest(std::pair<int, int> &std_p, std::pair<int, int> &std_p2, ft::pair<int, int> &ft_p, ft::pair<int, int> &ft_p2)
{
	std::vector<std::string> std;
	std::vector<std::string> ft;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	std.push_back((std_p == std_p2 ? "true" : "false"));
	ft.push_back((ft_p == ft_p2 ? "true" : "false"));

	operStr.push_back("!=");
	std.push_back((std_p != std_p2 ? "true" : "false"));
	ft.push_back((ft_p != ft_p2 ? "true" : "false"));

	operStr.push_back("<");
	std.push_back((std_p < std_p2 ? "true" : "false"));
	ft.push_back((ft_p < ft_p2 ? "true" : "false"));

	operStr.push_back("<=");
	std.push_back((std_p <= std_p2 ? "true" : "false"));
	ft.push_back((ft_p <= ft_p2 ? "true" : "false"));

	operStr.push_back(">");
	std.push_back((std_p > std_p2 ? "true" : "false"));
	ft.push_back((ft_p > ft_p2 ? "true" : "false"));

	operStr.push_back(">=");
	std.push_back((std_p >= std_p2 ? "true" : "false"));
	ft.push_back((ft_p >= ft_p2 ? "true" : "false"));

	operatePrint(operStr, ft, std);
}

void oper()
{
	testNamePrint("operator");

	std::pair<int, int> std_p;
	std::pair<int, int> std_p2;
	ft::pair<int, int> ft_p;
	ft::pair<int, int> ft_p2;

	std_p = std::make_pair(1, 1);
	std_p2 = std::make_pair(1, 1);
	ft_p = ft::make_pair(1, 1);
	ft_p2 = ft::make_pair(1, 1);
	print(ft_p, std_p);
	print(ft_p2, std_p2);
	operTest(std_p, std_p2, ft_p, ft_p2);

	std_p = std::make_pair(1, 2);
	std_p2 = std::make_pair(1, 2);
	ft_p = ft::make_pair(1, 2);
	ft_p2 = ft::make_pair(1, 2);
	print(ft_p, std_p);
	print(ft_p2, std_p2);
	operTest(std_p, std_p2, ft_p, ft_p2);

	std_p = std::make_pair(2, 1);
	std_p2 = std::make_pair(2, 1);
	ft_p = ft::make_pair(2, 1);
	ft_p2 = ft::make_pair(2, 1);
	print(ft_p, std_p);
	print(ft_p2, std_p2);
	operTest(std_p, std_p2, ft_p, ft_p2);
}
