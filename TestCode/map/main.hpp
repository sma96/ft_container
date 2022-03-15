#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <iomanip>

#include <vector>
#include <utility>
#include "../../map.hpp"
#include <map>
#include <list>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_NOMAL "\033[0m"
#define ANSI_COLOR_BLUE "\033[34m"
#define ANSI_COLOR_YELLOW "\033[33m"

void operatePrint(std::vector<std::string> oper, std::vector<std::string> ft, std::vector<std::string> std);
void print(ft::map<int, std::string> &ft_m, std::map<int, std::string> &std_m);
void printKey(ft::map<int, std::string> &ft_m, std::map<int, std::string> &std_m);
void printCount(int count);
void testNamePrint(std::string name);

void construct();
void empty();
void insert();
void erase();
void swap();
void clear();
void find();
void count();
void bound();
void equal_range();
void mapOperator();
void iterOper();
//void oper();

#endif
