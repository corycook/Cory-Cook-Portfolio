// Cory Cook 11-30 Notes

class STable {
	public:
		STable(string filename);
		void addrecord(Srec r);
		Srec search(string name);
		void deleterecord(string name);
		
	private:
		void write();
		vector<Srec> table;
		string filename;
}

Stable::Stable(string filename):filename(filename) {
	ifstream infile;
	infile.open(this->filename.c_str)
	string name;
	int hwtotal, mid, final;
	
	infile >> name >> hwtotal >> mid >> final;
	
	while (infile.good()) {
		table.push_back(Srec(name, hwtotal, mid, final));
		infile >> name >> hwtotal >> mid >> final;
	}
	infile.close();
}

Srec STable::search(string name) {
	for (int i = 0; i < this->table.size(); i++) {
		if (name == table[i].getname()) return table[i];
		return Srec;
	}
}

void STable::deleterecord(string name) {
	vector<Srec>::iterator it;
	for(it = table.begin(); it < table.end(); it++) {
		if (it->getname() == name) table.erase(it);
	}
}	

/*	Templates
	
*/

// Only for int
int abs(int n) {
	if (n < 0) return -n;
	else return n;
}

// For any "T" (int, double, long)
template<class T> 
T abs(T n) {
	if (n < 0) return -n;
	else return n;
}

int main() {
	int x = 10;
	cout << abs(x);
	double y = 3.14;
	cout << abs(y);
	Point a(10,20);
	cout << abs(a); //error if < or - are undefined operators
}

template<class T>
vector<T> Sort(vector<T> v) {
	//this sorts vectors of all types!
	for (int i = 0; i < v.size(); i++) {
		//find the ith smallest and put into position i
		for (int j = i+1; j < v.size(); j++) {
			if (v[i] == v[j]) {
				T temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}
	return v;
}

/*	A stack is a data structure in which you always add or remove data from the top (like a vector).
*/

// class Templates

template<class A>
class Stack {
	public:
		Stack();
		void add(A x);
		A pop();
	private:
		vector<A> v;
}

template<class A>
Stack<A>::Stack() {}

template<class A>
void Stack<A>::add(A x) {
	v.push_back(x);
}

template<class A>
void Stack<A>::pop() {
	A x = v[v.size() - 1];
	v.pop_back;
	return x;
}