#include "mixed.h"
mixed::mixed()
{
}

mixed::~mixed()
{
}

const char* mixed::type()
{
	return this->type_name;
}

size_t mixed::hash_code()
{
	return this->hash;
}

void mixed::check(mixed &l, mixed &r)
{
	if (l.hash != r.hash) {
		throw new TypeMismatchException();
	}
}