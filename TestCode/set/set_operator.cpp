#include "main.hpp"

void operatorTest(std::set<int> std_s, std::set<int> std_s2, ft::set<int> ft_s, ft::set<int> ft_s2)
{
	std::vector<std::string> std;
	std::vector<std::string> ft;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	std.push_back((std_s == std_s2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_s == ft_s2 ? "TRUE" : "FALSE"));

	operStr.push_back("!=");
	std.push_back((std_s != std_s2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_s != ft_s2 ? "TRUE" : "FALSE"));

	operStr.push_back("<");
	std.push_back((std_s < std_s2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_s < ft_s2 ? "TRUE" : "FALSE"));

	operStr.push_back("<=");
	std.push_back((std_s <= std_s2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_s <= ft_s2 ? "TRUE" : "FALSE"));

	operStr.push_back(">");
	std.push_back((std_s > std_s2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_s > ft_s2 ? "TRUE" : "FALSE"));

	operStr.push_back(">=");
	std.push_back((std_s >= std_s2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_s >= ft_s2 ? "TRUE" : "FALSE"));

	operatePrint(operStr, ft, std);
}

void setOperator()
{
	testNamePrint("set operator");
	std::list<int> std_lst;
	std::list<int> ft_lst;
	std::set<int> std_s;
	ft::set<int> ft_s;
	std::set<int> std_s2;
	ft::set<int> ft_s2;

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

	ft_s.insert(ft_lst.begin(), ft_lst.end());
	std_s.insert(std_lst.begin(), std_lst.end());
	ft_s2.insert(ft_lst.begin(), ft_lst.end());
	std_s2.insert(std_lst.begin(), std_lst.end());

	// ---------------[0]----------------
	printCount(0);
	print(ft_s, std_s);
	print(ft_s2, std_s2);
	operatorTest(std_s, std_s2, ft_s, ft_s2);

	// ---------------[1]----------------
	printCount(1);
	std_s.erase(++(++std_s.begin()));
	ft_s.erase(++(++ft_s.begin()));
	print(ft_s, std_s);
	print(ft_s2, std_s2);
	operatorTest(std_s, std_s2, ft_s, ft_s2);

	// ---------------[2]----------------
	printCount(2);
	std_s2.erase(std_s2.begin());
	ft_s2.erase(ft_s2.begin());
	print(ft_s, std_s);
	print(ft_s2, std_s2);
	operatorTest(std_s, std_s2, ft_s, ft_s2);
}
