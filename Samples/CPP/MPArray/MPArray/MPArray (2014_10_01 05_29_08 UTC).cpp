// MPArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <amp.h>
using namespace concurrency;


int _tmain(int argc, _TCHAR* argv[])
{
	int n = 1000000;
	if (argc == 2) n = atoi((const char *)argv[1]);
	int* arr = new int[n];
	int start = clock();
	array_view<int, 1> a(n, arr);
	parallel_for_each(a.extent, [=](index<1> i) restrict(amp) { a[i] = 0; });
	arr = a.data();
	std::cout << arr[n-1] << " in " << clock() - start << std::endl;
	system("pause");
}
