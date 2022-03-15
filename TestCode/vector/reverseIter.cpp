#include "main.hpp"

void operTest(std::vector<int>::reverse_iterator std_iter, std::vector<int>::reverse_iterator std_iter2, ft::vector<int>::reverse_iterator ft_iter, ft::vector<int>::reverse_iterator ft_iter2)
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

	operStr.push_back("<");
	std.push_back((std_iter < std_iter2 ? "true" : "false"));
	ft.push_back((ft_iter < ft_iter2 ? "true" : "false"));

	operStr.push_back("<=");
	std.push_back((std_iter <= std_iter2 ? "true" : "false"));
	ft.push_back((ft_iter <= ft_iter2 ? "true" : "false"));

	operStr.push_back(">");
	std.push_back((std_iter > std_iter2 ? "true" : "false"));
	ft.push_back((ft_iter > ft_iter2 ? "true" : "false"));

	operStr.push_back(">=");
	std.push_back((std_iter >= std_iter2 ? "true" : "false"));
	ft.push_back((ft_iter >= ft_iter2 ? "true" : "false"));

	operatePrint(operStr, ft, std);
}

void operTest2(std::vector<int>::reverse_iterator stdIter, ft::vector<int>::reverse_iterator ftIter)
{
	std::vector<std::string> std;
	std::vector<std::string> ft;
	std::vector<std::string> operStr;
	std::string str;

	str.assign("0");

	operStr.push_back("i++");
	str[0] = *(stdIter++) + '0';
	std.push_back(str);
	str[0] = *(ftIter++) + '0';
	ft.push_back(str);

	operStr.push_back("++i");
	str[0] = *(++stdIter) + '0';
	std.push_back(str);
	str[0] = *(++ftIter) + '0';
	ft.push_back(str);

	operStr.push_back("i--");
	str[0] = *(stdIter--) + '0';
	std.push_back(str);
	str[0] = *(ftIter--) + '0';
	ft.push_back(str);

	operStr.push_back("--i");
	str[0] = *(--stdIter) + '0';
	std.push_back(str);
	str[0] = *(--ftIter) + '0';
	ft.push_back(str);

	operStr.push_back("it + n");
	str[0] = *(stdIter + 1) + '0';
	std.push_back(str);
	str[0] = *(ftIter + 1) + '0';
	ft.push_back(str);

	// operStr.push_back("n + it");
	// str[0] = *(1 + stdIter) + '0';
	// std.push_back(str);
	// str[0] = *(1 + ftIter) + '0';
	// ft.push_back(str);

	stdIter++;
	ftIter++;
	operStr.push_back("it - n");
	str[0] = *(stdIter - 1) + '0';
	std.push_back(str);
	str[0] = *(ftIter - 1) + '0';
	ft.push_back(str);

	std::vector<int>::reverse_iterator stdTemp;
	ft::vector<int>::reverse_iterator ftTemp;

	stdTemp = stdIter + 1;
	ftTemp = ftIter + 1;

	operStr.push_back("it - it");
	str[0] = stdTemp - stdIter + '0';
	std.push_back(str);
	str[0] = ftTemp - ftIter + '0';
	ft.push_back(str);

	operStr.push_back("it += it");
	stdIter += 1;
	str[0] = *stdIter + '0';
	std.push_back(str);
	ftIter += 1;
	str[0] = *ftIter + '0';
	ft.push_back(str);

	operStr.push_back("it[n]");
	str[0] = stdIter[0] + '0';
	std.push_back(str);
	str[0] = ftIter[0] + '0';
	ft.push_back(str);

	operStr.push_back("base");
	str[0] = *stdIter.base() + '0';
	std.push_back(str);
	str[0] = *ftIter.base() + '0';
	ft.push_back(str);

	operatePrint(operStr, ft, std);
}

void reverseIter()
{
	testNamePrint("reverse iterator");

	std::vector<int> std_v;
	ft::vector<int> ft_v;

	for (int i = 1; i < 4; i++)
	{
		std_v.push_back(i * 3);
		ft_v.push_back(i * 3);
	}

	operTest(std_v.rbegin(), std_v.rend(), ft_v.rbegin(), ft_v.rend());
	operTest(std_v.rbegin(), std_v.rbegin(), ft_v.rbegin(), ft_v.rbegin());

	operTest2(std_v.rbegin(), ft_v.rbegin());
}
