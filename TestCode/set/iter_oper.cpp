#include "main.hpp"

void operTest(std::set<int>::iterator std_iter, std::set<int>::iterator std_iter2, ft::set<int>::iterator ft_iter, ft::set<int>::iterator ft_iter2)
{
	std::vector<std::string> std;
	std::vector<std::string> ft;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	std.push_back((std_iter == std_iter2 ? "true" : "false"));
	ft.push_back((ft_iter == ft_iter2 ? "true" : "false"));

	operStr.push_back("!=");
	std.push_back((std_iter != std_iter2 ? "true" : "false"));
	ft.push_back((ft_iter != ft_iter2 ? "true" : "false"));

	operatePrint(operStr, ft, std);
}
void iterOper()
{
	testNamePrint("iterator operator");
	std::list<int> std_lst;
	std::list<int> ft_lst;
	std::set<int> std_s;
	ft::set<int> ft_s;

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

	// ------------------[0]-----------------
	printCount(0);
	operTest(std_s.begin(), std_s.begin(), ft_s.begin(), ft_s.begin());

	// ------------------[1]-----------------
	printCount(1);
	operTest(std_s.begin(), ++std_s.begin(), ft_s.begin(), ++ft_s.begin());
}
