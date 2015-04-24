// Templates

template<class Type> // template<typename Type> // would work as well
Type min(Type a, Type b) {
	if (a < b) return a;
	else return b;
}

int x = 10;
int y = 15;
double z = 3.14;
cout << min(x,y);
// cout << min(x,z); // cannot perform action because z is not type int
cout << min<double>(x,z); // specifies that doubles will be passed to the function in place of Type

template<class A>
class Stack {
	public:
		Stack();
		Stack(vector<A> v);
		void add(A x);
		A pop();
	private:
		vector<A> v;
}

template<class A>
Stack<A>::Stack(vector<A> v):v(v) {}

Stack<int> s1;
vector<double> t1;
t1.push_back(3.14);
t1.push_back(.367);
t1.push_back(714);
Stack s2(t1);
cout << s2.pop();