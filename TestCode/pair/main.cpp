#include "main.hpp"

int main(void)
{
	testNamePrint("pair");
	construct();
	oper();

	system("leaks test");
	return (0);
}
