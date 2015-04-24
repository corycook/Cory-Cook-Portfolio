#include "test.h"


test::test()
{
	one = Property<int, test>(this, get_one, set_one);
	two = Property<int, test>(this, get_two, set_two);
}


test::~test()
{
}

int test::get_one(test* cls)
{
	return cls->o;
}

int test::get_two(test* cls)
{
	return cls->t;
}

void test::set_one(test* cls, int val)
{
	cls->o = val;
}

void test::set_two(test* cls, int val)
{
	cls->t = val;
}