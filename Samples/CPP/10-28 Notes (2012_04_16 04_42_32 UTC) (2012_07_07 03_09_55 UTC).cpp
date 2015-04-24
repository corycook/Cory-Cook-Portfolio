/*	10-28-10
	Pointers
*/

int x = 10;
int* p;
p = &x; // p is equal to the address of x
x++;
*p = *p + 10;
cout << *p << x; //both *p and x will always be equal since they point to the same location

int *t = new int;
*t = 10;
cout << *t;
delete t;

Circle* c;
c = new Circle(Point(0,0); s);
cwin << *c;
delete c;

// ARRAYS

char c[3], d[4];
d = "cat"; // ends in null char '\0'
c = "mouse";

void printcstring(char* a, int s) {
// a is a character array and s is the size
	cout << a; // a is an array
}

int main() {
	char[5] c;
	c = "Dog";
	printcstring(c, 5);
}

// Pointer for vectors: ITERATOR

vector<int> v;
for (int i=0; i < 1000; i++) {
	v.push_back(i*5);
}

/*	Old method
for (int i=0; i < v.size(); i++) {
	if (v[i] == 328)
		cout << v[i] <<" found!";
}
*/

vector<int>::iterator it;
it = v.begin();

/*	Iterators
		it = v.begin();
			it points to the front
		it = v.end();
			it points past the last element in v
	moving the iterator:
		it++
			moves the iterator up one
		it+n
			moves the iterator up n
		it--
			moves the iterator down one
		it-n
			moves the iterator down n
		it=n
			moves the iterator to position n
*/

cout << *it; // cout v[0]
//it = v.end();
//cout << *it;

// find 625 in vector v
vector<int>::iterator it; //'it' can be anything you choose
for(it = v.begin(); it != v.end(); it++) {
	if (*it == 652)
		cout << *it << " is found";
}

//Example2

vector<int> v;
vector<int>::iterator p;
for (p = v.begin(); p != v.end; p++) {
	if(*p == 625)
		v.erase(p); // location p is removed and the vector is shrunk
}

/*	vectors
		v.push_back(x)
			add x to the end of v
		v.pop_back(x)
			remove from end of v
*/

v.erase(v.begin()); // Erases the first element of v

/*	insert - add to front
		v.insert(p, e)
			where p is an iterator and e is the value to be added
		v.erase(p)
			where p is the iterator
	v.begin() and v.end() are iterator elements of vectors
*/
v.insert(v.begin(), x)

/*	insert and erase for vectors
		let v be a vector
		let p be an iterator
		let x be a value
		v.erase(p)
		v.insert(p,x)
*/

int find(int x, vector<int>::iterator t1, vector<int>::iterator t2) {
	//find if x is in the vector
	vector<int>:: iterator p;
	for (p = t1; p != t2; p++) {
		if (*p == x)
			return 1
		else
			return 0
	}
}

vector<int> v;
cout << find(5322, v.begin(), v.end());