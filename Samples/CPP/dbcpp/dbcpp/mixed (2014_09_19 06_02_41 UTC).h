#pragma once
#include <typeinfo>
#include <exception>

class TypeMismatchException : std::exception
{
};

class mixed
{
	void* value;
	const char* type_name;
	size_t hash;
	bool(*gt)(mixed&, mixed&);
	bool(*gte)(mixed&, mixed&);
	bool(*lt)(mixed&, mixed&);
	bool(*lte)(mixed&, mixed&);
	bool(*eq)(mixed&, mixed&);
	bool(*ne)(mixed&, mixed&);

	static void check(mixed&, mixed&);
public:
	mixed();
	~mixed();
	const char* type();
	size_t hash_code();

	template<class T>
	mixed(T v)
	{
		value = static_cast<void*>(new T(v));
		type_name = typeid(v).name();
		hash = typeid(v).hash_code();
		gt = greater_than<T>;
		gte = greater_than_equal<T>;
		lt = less_than<T>;
		lte = less_than_equal<T>;
		eq = equal<T>;
		ne = not_equal<T>;
	}

	template<class T>
	operator T() { return *static_cast<T*>(value); }
	bool operator>(mixed &r) { return gt(*this, r); }
	bool operator>=(mixed &r) { return gte(*this, r); }
	bool operator<(mixed &r) { return lt(*this, r); }
	bool operator<=(mixed &r) { return lte(*this, r); }
	bool operator==(mixed &r) { return eq(*this, r); }
	bool operator!=(mixed &r) { return ne(*this, r); }
	
	template<class T>
	static bool greater_than(mixed &l, mixed &r)
	{
		check(l, r);
		return static_cast<T>(l) > static_cast<T>(r);
	}

	template<class T>
	static bool greater_than_equal(mixed &l, mixed &r)
	{
		check(l, r);
		return static_cast<T>(l) >= static_cast<T>(r);
	}

	template<class T>
	static bool less_than(mixed &l, mixed &r)
	{
		check(l, r);
		return static_cast<T>(l) < static_cast<T>(r);
	}

	template<class T>
	static bool less_than_equal(mixed &l, mixed &r)
	{
		check(l, r);
		return static_cast<T>(l) <= static_cast<T>(r);
	}

	template<class T>
	static bool equal(mixed &l, mixed &r)
	{
		check(l, r);
		return static_cast<T>(l) == static_cast<T>(r);
	}

	template<class T>
	static bool not_equal(mixed &l, mixed &r)
	{
		check(l, r);
		return static_cast<T>(l) != static_cast<T>(r);
	}
};

