#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <iomanip>

#include <vector>
#include <utility>
#include "../../set.hpp"
#include <set>
#include <list>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_NOMAL "\033[0m"
#define ANSI_COLOR_BLUE "\033[34m"
#define ANSI_COLOR_YELLOW "\033[33m"

void operatePrint(std::vector<std::string> oper, std::vector<std::string> ft, std::vector<std::string> std);
void print(ft::set<int> &ft_s, std::set<int> &std_s);
void print(ft::set<std::string> &ft_s, std::set<std::string> &std_s);
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
void setOperator();
void iterOper();

#endif
