#include "main.hpp"

int main(void)
{
	testNamePrint("stack");
	construct();
	oper();

	system("leaks test");
	return (0);
}
