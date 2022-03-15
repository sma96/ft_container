#include "main.hpp"

int main(void)
{
	testNamePrint("map");
	construct();
	empty();
	insert();
	erase();
	swap();
	clear();
	find();
	count();
	bound();
	equal_range();
	setOperator();
	iterOper();

	system("leaks test");
	return (0);
}
