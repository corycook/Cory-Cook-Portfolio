#pragma once

#include "Property.h"

class test
{
	int o, t;
	static int get_one(test* cls);
	static void set_one(test* cls, int val);
	static int get_two(test* cls);
	static void set_two(test* cls, int val);
public:
	Property<int, test> one;
	Property<int, test> two;
	test();
	~test();
};

