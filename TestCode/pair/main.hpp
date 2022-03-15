#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <iomanip>

#include <vector>
#include <utility>
#include "../../pair.hpp"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_NOMAL "\033[0m"
#define ANSI_COLOR_BLUE "\033[34m"
#define ANSI_COLOR_YELLOW "\033[33m"

void operatePrint(std::vector<std::string> oper, std::vector<std::string> ft, std::vector<std::string> std);
void print(ft::pair<int, int> &ft_p, std::pair<int, int> &std_p);
void testNamePrint(std::string name);

void construct();
void oper();

#endif
