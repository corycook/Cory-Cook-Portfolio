
#include <iostream>
#include "test.h"

int main()
{
	test first;
	test second;
	first.one = 1000;
	second.one = 2000;
	std::cout << first.one << std::endl << second.one << std::endl;
	system("pause");
}