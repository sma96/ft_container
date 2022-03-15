#include "main.hpp"

void operatorTest(std::map<int, std::string> std_m, std::map<int, std::string> std_m2, ft::map<int, std::string> ft_m, ft::map<int, std::string> ft_m2)
{
	std::vector<std::string> std;
	std::vector<std::string> ft;
	std::vector<std::string> operStr;

	operStr.push_back("==");
	std.push_back((std_m == std_m2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_m == ft_m2 ? "TRUE" : "FALSE"));

	operStr.push_back("!=");
	std.push_back((std_m != std_m2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_m != ft_m2 ? "TRUE" : "FALSE"));

	operStr.push_back("<");
	std.push_back((std_m < std_m2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_m < ft_m2 ? "TRUE" : "FALSE"));

	operStr.push_back("<=");
	std.push_back((std_m <= std_m2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_m <= ft_m2 ? "TRUE" : "FALSE"));

	operStr.push_back(">");
	std.push_back((std_m > std_m2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_m > ft_m2 ? "TRUE" : "FALSE"));

	operStr.push_back(">=");
	std.push_back((std_m >= std_m2 ? "TRUE" : "FALSE"));
	ft.push_back((ft_m >= ft_m2 ? "TRUE" : "FALSE"));

	operatePrint(operStr, ft, std);
}

void mapOperator()
{
	testNamePrint("map operator");
	std::list<std::pair<int, std::string> > std_lst;
	std::list<ft::pair<int, std::string> > ft_lst;
	std::map<int, std::string> std_m;
	ft::map<int, std::string> ft_m;
	std::map<int, std::string> std_m2;
	ft::map<int, std::string> ft_m2;

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
	ft_m2.insert(ft_lst.begin(), ft_lst.end());
	std_m2.insert(std_lst.begin(), std_lst.end());

	// ---------------[0]----------------
	printCount(0);
	printKey(ft_m, std_m);
	printKey(ft_m2, std_m2);
	operatorTest(std_m, std_m2, ft_m, ft_m2);

	// ---------------[1]----------------
	printCount(1);
	std_m.erase(++(++std_m.begin()));
	ft_m.erase(++(++ft_m.begin()));
	printKey(ft_m, std_m);
	printKey(ft_m2, std_m2);
	operatorTest(std_m, std_m2, ft_m, ft_m2);

	// ---------------[2]----------------
	printCount(2);
	std_m2.erase(std_m2.begin());
	ft_m2.erase(ft_m2.begin());
	printKey(ft_m, std_m);
	printKey(ft_m2, std_m2);
	operatorTest(std_m, std_m2, ft_m, ft_m2);
}
