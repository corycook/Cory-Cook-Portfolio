/*	Cory Cook
	Notes 11-18-2010
*/

class Pair {
	Pair(int x, int y)
	int getx();
	int gety();
	
	bool operator==(Pair q);
	bool operator!=(Pair q);
	Pair operator+(Pair q);
	Pair operator-(Pair q);
	void operator++(); // Prefix operator (++p)
	void operator++(Pair); // Postfix operator (p++)
	
	private:
	int x;
	int y;
}

// Creates an operator for ==

bool Pair::operator==(Pair q) {
	if (this->x != q.getx())
		return false;
	if (this->y != q.gety())
		return false;
	return true;
}

// Creates an operator for !=

bool Pair::operator!=(Pair q) {
	if (this->x != q.getx())
		return true;
	if (this->y != q.gety())
		return true;
	return false;
}

// Creates an operator for +

Pair Pair::operator+(Pair q) {
	int a = 0, b = 0;
	a = this->x + q.getx();
	b = this->y + q.gety();
	return Pair(a,b);
}

// Creates an operator for -

Pair Pair::operator-(Pair q) {
	int a = 0, b = 0;
	a = this->x - q.getx();
	b = this->y - q.gety();
	return Pair(a,b);
}

// Prefix operator for ++ (++p)

void Pair::operator++() {
	this->x++;
	this->y++;
}

// Postfix operator for ++ (p++)

void Pair::operator++(Pair) {
	this->x++;
	this->y++;
}

int main() {
	Pair p(10,10);
	Pair q(20,20);
	if (p==q) {
		cout << "same pair";
	}
	Pair r = p + q;
	++p;
}

// Polymorphism Review
//

dog* p;
p = new terrier(...);
cout << p->getsize();

// in order to output the function for the derived class terrier you need
// to declare a virtual function in base class dog

vector<dog*> v;
dog* x = new spaniel();
v.push_back(x);
void outputdogsize(dog* d) {
	cout << d->getsize();
}

// Streams File I/O
//	-open file and read from it
//	-open file write to it

#include <fstream>
/* fstream is a C library for file i/o
	3 types of objects
		ifstream : input
		ofstream : output
		fstream : both
*/

// ofstream - write 1,000,000 numbers to file

int main() {
	string filename;
	ofstream ofile;
	cout << "Enter the file name to win";
	cin >> filename;
	ofile.open(filename.c_str()); // Filename has to be a cstring
	// ofile.open("ofile.txt"); will also work for programmer defined name
	for (int i = 0; i < 1000000; i++) {
		ofile << i << endl;
	}
}
// ofstream will clobber an existing file
// instead of using cout use file handle