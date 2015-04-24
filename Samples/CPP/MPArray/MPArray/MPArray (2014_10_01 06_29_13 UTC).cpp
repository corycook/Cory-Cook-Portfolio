// MPArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <amp.h>
using namespace concurrency;


int _tmain(int argc, char ** argv)
{
	int n = 100000000;
	if (argc == 2) n = atoi(argv[1]);
	std::cout << "Begin Linear Test" << std::endl;
	int* arra = new int[n];
	int start = clock();
	for (int i = 0; i < n; i++)
	{
		arra[i] = i;
	}
	std::cout << arra[n - 1] << " in " << clock() - start << std::endl;

	std::cout << "Begin Parallel Test" << std::endl;
	std::cout << "Run length: " << n << std::endl;
	int* arr = new int[n];
	start = clock();
	array_view<int, 1> a(n, arr);
	parallel_for_each(a.extent, [=](index<1> i) restrict(amp) { a[i] = a.section(i).data() - a.data(); });
	arr = a.data();
	std::cout << arr[n-1] << " in " << clock() - start << std::endl;
}
