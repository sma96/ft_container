#include "main.hpp"

void operTest(std::vector<int> &std_v, std::vector<int> &std_v2, ft::vector<int> &ft_v, ft::vector<int> &ft_v2)
{
	std::vector<std::string> std;
	std::vector<std::string> ft;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	std.push_back((std_v == std_v2 ? "true" : "false"));
	ft.push_back((ft_v == ft_v2 ? "true" : "false"));

	operStr.push_back("!=");
	std.push_back((std_v != std_v2 ? "true" : "false"));
	ft.push_back((ft_v != ft_v2 ? "true" : "false"));

	operStr.push_back("<");
	std.push_back((std_v < std_v2 ? "true" : "false"));
	ft.push_back((ft_v < ft_v2 ? "true" : "false"));

	operStr.push_back("<=");
	std.push_back((std_v <= std_v2 ? "true" : "false"));
	ft.push_back((ft_v <= ft_v2 ? "true" : "false"));

	operStr.push_back(">");
	std.push_back((std_v > std_v2 ? "true" : "false"));
	ft.push_back((ft_v > ft_v2 ? "true" : "false"));

	operStr.push_back(">=");
	std.push_back((std_v >= std_v2 ? "true" : "false"));
	ft.push_back((ft_v >= ft_v2 ? "true" : "false"));

	operatePrint(operStr, ft, std);
}

void oper()
{
	testNamePrint("operator");

	std::vector<int> std_v;
	std::vector<int> std_v2;
	ft::vector<int> ft_v;
	ft::vector<int> ft_v2;

	for (int i = 1; i < 5; i++)
	{
		std_v.push_back(i * 3);
		std_v2.push_back(i * 3);
		ft_v.push_back(i * 3);
		ft_v2.push_back(i * 3);
	}
	print(ft_v, std_v);
	print(ft_v2, std_v2);
	operTest(std_v, std_v2, ft_v, ft_v2);

	std_v2.push_back(2);
	ft_v2.push_back(2);
	print(ft_v, std_v);
	print(ft_v2, std_v2);
	operTest(std_v, std_v2, ft_v, ft_v2);

	std_v.push_back(1);
	ft_v.push_back(1);
	print(ft_v, std_v);
	print(ft_v2, std_v2);
	operTest(std_v, std_v2, ft_v, ft_v2);

	std_v.erase(std_v.begin() + 2, std_v.end());
	ft_v.erase(ft_v.begin() + 2, ft_v.end());
	std_v.push_back(15);
	ft_v.push_back(15);
	print(ft_v, std_v);
	print(ft_v2, std_v2);
	operTest(std_v, std_v2, ft_v, ft_v2);

}
