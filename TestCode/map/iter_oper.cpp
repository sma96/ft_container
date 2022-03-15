#include "main.hpp"

void operTest(std::map<int, std::string>::iterator std_iter, std::map<int, std::string>::iterator std_iter2, ft::map<int,std::string>::iterator ft_iter, ft::map<int, std::string>::iterator ft_iter2)
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
	std::list<std::pair<int, std::string> > std_lst;
	std::list<ft::pair<int, std::string> > ft_lst;
	std::map<int, std::string> std_m;
	ft::map<int, std::string> ft_m;

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

	// ------------------[0]-----------------
	printCount(0);
	operTest(std_m.begin(), std_m.begin(), ft_m.begin(), ft_m.begin());

	// ------------------[1]-----------------
	printCount(1);
	operTest(std_m.begin(), ++std_m.begin(), ft_m.begin(), ++ft_m.begin());
}
