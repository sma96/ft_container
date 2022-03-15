#include "main.hpp"

void operTest(std::stack<int> &std_s, std::stack<int> &std_s2, ft::stack<int> &ft_s, ft::stack<int> &ft_s2)
{
	std::vector<std::string> std;
	std::vector<std::string> ft;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	std.push_back((std_s == std_s2 ? "true" : "false"));
	ft.push_back((ft_s == ft_s2 ? "true" : "false"));

	operStr.push_back("!=");
	std.push_back((std_s != std_s2 ? "true" : "false"));
	ft.push_back((ft_s != ft_s2 ? "true" : "false"));

	operStr.push_back("<");
	std.push_back((std_s < std_s2 ? "true" : "false"));
	ft.push_back((ft_s < ft_s2 ? "true" : "false"));

	operStr.push_back("<=");
	std.push_back((std_s <= std_s2 ? "true" : "false"));
	ft.push_back((ft_s <= ft_s2 ? "true" : "false"));

	operStr.push_back(">");
	std.push_back((std_s > std_s2 ? "true" : "false"));
	ft.push_back((ft_s > ft_s2 ? "true" : "false"));

	operStr.push_back(">=");
	std.push_back((std_s >= std_s2 ? "true" : "false"));
	ft.push_back((ft_s >= ft_s2 ? "true" : "false"));

	operatePrint(operStr, ft, std);
}

void oper()
{
	testNamePrint("operator");

	std::stack<int> std_v;
	std::stack<int> std_v2;
	ft::stack<int> ft_v;
	ft::stack<int> ft_v2;

	for (int i = 1; i < 4; i++)
	{
		std_v.push(i * 3);
		std_v2.push(i * 3);
		ft_v.push(i * 3);
		ft_v2.push(i * 3);
	}

	print(ft_v, std_v);
	print(ft_v2, std_v2);
	operTest(std_v, std_v2, ft_v, ft_v2);

	std_v2.push(2);
	ft_v2.push(2);
	print(ft_v, std_v);
	print(ft_v2, std_v2);
	operTest(std_v, std_v2, ft_v, ft_v2);

	std_v.push(1);
	ft_v.push(1);
	print(ft_v, std_v);
	print(ft_v2, std_v2);
	operTest(std_v, std_v2, ft_v, ft_v2);

	std_v.pop();
	std_v.pop();
	ft_v.pop();
	ft_v.pop();
	std_v.push(15);
	ft_v.push(15);
	print(ft_v, std_v);
	print(ft_v2, std_v2);
	operTest(std_v, std_v2, ft_v, ft_v2);

}
