#include "Assembler.h"
#include "VirtualMachine.h"
#include <iostream>
using namespace std;

int main() {
	int16 test;
	test = 255;
	printf("%i (%i):%i (%i)\r\n", (int) test.high, sizeof(test.high),
		(int) test.low, sizeof(test.low));
	printf("value: %i, size: %i\r\n", test, sizeof(test));
	system("pause");
}