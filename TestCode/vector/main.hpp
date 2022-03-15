#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <iomanip>

#include <vector>
#include "../../vector.hpp"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_NOMAL "\033[0m"
#define ANSI_COLOR_BLUE "\033[34m"
#define ANSI_COLOR_YELLOW "\033[33m"

void operatePrint(std::vector<std::string> oper, std::vector<std::string> ft, std::vector<std::string> std);
void print(ft::vector<int> &v, std::vector<int> &std_v);
void testNamePrint(std::string name);
void construct();
void resize();
void reserve();
void at();
void front();
void back();
void assign();
void push_back();
void pop_back();
void insert();
void erase();
void swap();
void clear();
void oper();
void iterOper();
void reverseIter();

#endif
