#include "main.hpp"

int main(void)
{
	construct();
	resize();
	reserve();
	at();
	front();
	back();
	assign();
	push_back();
	pop_back();
	insert();
	erase();
	swap();
	clear();
	oper();
	iterOper();
	reverseIter();

	system("leaks test");
	return (0);
}
