
#include <iostream>
#include "test.h"

int main()
{
	test first;
	test second;
	first.one = 1000;
	first.two = 10000;
	second.one = 2000;
	second.two = 20000;
	std::cout << first.one << std::endl << first.two << std::endl
		<< second.one << std::endl << second.two << std::endl;
}