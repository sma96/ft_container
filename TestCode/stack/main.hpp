#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <iomanip>

#include <stack>
#include <vector>
#include <deque>
#include "../../stack.hpp"
#include "../../vector.hpp"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_NOMAL "\033[0m"
#define ANSI_COLOR_BLUE "\033[34m"
#define ANSI_COLOR_YELLOW "\033[33m"


void operatePrint(std::vector<std::string> oper, std::vector<std::string> ft, std::vector<std::string> std);
void testNamePrint(std::string name);
void print(ft::stack<int> v, std::stack<int> std_v);
void print(ft::stack<int, ft::vector<int> > v, std::stack<int, std::vector<int> > std_v);

void construct();
void oper();

#endif
