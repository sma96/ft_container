#include "main.hpp"

static void printIter(std::map<int, std::string>::iterator &std_it, ft::map<int, std::string>::iterator &ft_it, std::map<int, std::string> &std_m, ft::map<int, std::string> &ft_m)
{
	std::string std_ret;
	std::string ft_ret;

	std_ret = (std_it != std_m.end() ? std_it->second : "not find");
	ft_ret = (ft_it != ft_m.end() ? ft_it->second : "not find");
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << ft_ret;
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | ";
	std::cout << ANSI_COLOR_NOMAL;
	std::cout << std::setw(8) << "ret : ";
	std::cout << std::setw(7) << std_ret;
	std::cout << ANSI_COLOR_YELLOW;
	std::cout << std::setw(5) << " | " << std::setw(10) <<
		(std_ret == ft_ret ? ANSI_COLOR_GREEN"OK" : ANSI_COLOR_RED"KO") << ANSI_COLOR_NOMAL << std::endl;
}

void bound()
{
	testNamePrint("bound");

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

	std::map<int, std::string> std_m;
	ft::map<int, std::string> ft_m;
	std::map<int, std::string>::iterator std_it;
	ft::map<int, std::string>::iterator ft_it;
	ft_m.insert(ft_lst.begin(), ft_lst.end());
	std_m.insert(std_lst.begin(), std_lst.end());

	// -------------[0]-------------
	printCount(0);
	print(ft_m, std_m);
	
	// -------------[1]-------------
	// 제일 적은 값보다 더 작은 값
	printCount(1);
	std_it = std_m.lower_bound(-5);
	ft_it = ft_m.lower_bound(-5);
	printIter(std_it, ft_it, std_m, ft_m);

	// -------------[2]-------------
	// 제일 작은 값
	printCount(0);
	std_it = std_m.lower_bound(2);
	ft_it = ft_m.lower_bound(2);
	printIter(std_it, ft_it, std_m, ft_m);

	// -------------[3]-------------
	// 중간 값
	printCount(3);
	std_it = std_m.lower_bound(10);
	ft_it = ft_m.lower_bound(10);
	printIter(std_it, ft_it, std_m, ft_m);

	// -------------[4]-------------
	// 최대 값
	printCount(4);
	std_it = std_m.lower_bound(23);
	ft_it = ft_m.lower_bound(23);
	printIter(std_it, ft_it, std_m, ft_m);

	// -------------[5]-------------
	// 최대 이상
	printCount(5);
	std_it = std_m.lower_bound(100);
	ft_it = ft_m.lower_bound(100);
	printIter(std_it, ft_it, std_m, ft_m);


	// -------------[6]-------------
	// 제일 적은 값보다 더 작은 값
	printCount(6);
	std_it = std_m.upper_bound(-5);
	ft_it = ft_m.upper_bound(-5);
	printIter(std_it, ft_it, std_m, ft_m);

	// -------------[7]-------------
	// 제일 작은 값
	printCount(7);
	std_it = std_m.upper_bound(0);
	ft_it = ft_m.upper_bound(0);
	printIter(std_it, ft_it, std_m, ft_m);

	// -------------[8]-------------
	// 중간 값
	printCount(8);
	std_it = std_m.upper_bound(10);
	ft_it = ft_m.upper_bound(10);
	printIter(std_it, ft_it, std_m, ft_m);

	// -------------[9]-------------
	// 최대 값
	printCount(9);
	std_it = std_m.upper_bound(23);
	ft_it = ft_m.upper_bound(23);
	printIter(std_it, ft_it, std_m, ft_m);

	// -------------[10]-------------
	// 최대 값 초과
	printCount(10);
	std_it = std_m.upper_bound(100);
	ft_it = ft_m.upper_bound(100);
	printIter(std_it, ft_it, std_m, ft_m);


}
