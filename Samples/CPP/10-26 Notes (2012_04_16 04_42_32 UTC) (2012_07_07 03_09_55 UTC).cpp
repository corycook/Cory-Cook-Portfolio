/* Strings
	A string is a vector of characters
	string s = "Hello";
	cout << s[3];
	s[3] = 'i';
	cout << s;
	
	functions for stings:
		s.length()
		s.erase()
		s.substr(k,n) //where k is position and n is # of characters
		cout << s.substr(0,4) << "!"; 
*/

//Write a function to find string s1 in string s2

int position(string s1, string s2) {
	for (int i=0; i <= s2.length()-s1.length(); i++) {
		if (s2.substr(i, s1.length()) == s1) {
			return i;
		}
	}
	return -1;
}

/*
	Note on c strings (char arrays)
		char c[6]="Hello";
			6 because last space is for necessary null character "\0"
		int x = 42;
			do not use cstrings
		c_str()
			this converts a C++ string to a C string
		string s = "Hello";
		char t[6] = s.c_str();
*/

// Pointers
/*
	Circle c = Circle(Point(0,0),5);
	new Circle(Point(0,0),5);	// Allocates an object
	
	Circle* p;	// Pointer to allocated object
	
	Circle* p = new Circle(Point (0,0),5);
	
	p->move(dx,dy);
		use p->function to utilize a function on what p points to
		
	cwin << *p
		*p is the object that p points to
*/

// declare a pointer
int* x; //x points to an integer

//address operator &
int y = 10; // variable y

x = &y; //now x points to y

int y;
cout << &y; // prints the memory address

y = y + 10;
*x = *x + 10;

/*
	Pointers - operators
		*	applied to pointer to get contents(object) where pointer points.
		&	address of an object (int, double, etc.)
		->	used to apply a function to an object
*/

// Problem 1
int i = 10;
int* j = &i;
*j++;
cout << *j;	// Outputs 11

// Problem 2
Point p(5,10);
Point *q;
q = &p;
cout << q->get_x(); // Outputs 5

/*
	Cautions about pointers:
		-dangling pointers
			using a pointer that was never assigned
				int* x;
				*x = 15;
		-memory leak
			continuously creating new objects
	delete p; // deletes object where p is pointing
*/

// Program with a memory leak:
Point *k
vector<Point>* v;
int i=1; j=1;
while(true) {
	k = new Point(i,j);
	v.pushback(k);
	i++
	j++
}