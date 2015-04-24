#ifndef PROPERTY_H
#define PROPERTY_H

template <typename T, class S>
// The property class allows you to define a class property using static methods.
//  Instantiate the property in the class constructor by passing a class pointer
//  and either the static get method, static set method, or both.
//  Access the property or assign a value to it to call the property accessors.
//  The accessors must take a class pointer as their first argument.
class Property {
private:
	S* classptr;
	T(*getter)(S*);
	void(*setter)(S*, T);
	static T default_getter(S*)
	{
		throw "Cannot read property";
	}
	static void default_setter(S*, T value)
	{
		throw "Cannot write property";
	}
public:
	Property() { }
	Property(S* cls, T(*get)(S*), void(*set)(S*, T)) : classptr(cls), getter(get), setter(set) { }
	Property(S* cls, T(*get)(S*)) { init(cls, get, default_setter); }
	Property(S* cls, void(*set)(S*, T)) { init(cls, default_getter, set); }
	void init(S* cls, T(*get)(S*), void(*set)(S*, T))
	{
		classptr = cls;
		getter = get;
		setter = set;
	}
	void operator=(T value) { setter(classptr, value); }
	operator T() { return getter(classptr); }
};

#endif
