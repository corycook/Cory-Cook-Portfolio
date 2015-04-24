/*	Cory Cook
	11-16-2010
*/

/*	Multiple Inheritance (situation)
		Person
			Employee
			Student
			
				Workstudy (inherits both employee and student)
					This is called cycling because Person is inherited multiple times
*/
				
	class Person {
		public:
			Person(string name);
		private:
			string name;
	}
	
	class Employee:public Person {
		public:
			Employee(string name, string ssid);
		private:
			string ssid;
	}
	
	class Student:public Person {
		public:
			Student(string name, string sid);
		private:
			string sid;
	}
	
	class Workstudy:public Student, public Employee {
		public:
			Workstudy(string name, string ssid, string sid, string dept);
		private:
			string dept;
	}
	
	Workstudy::Workstrudy(string name, string ssid, string sid, string dept)
		:Student(name, sid), Employee(name, ssid), dept(dept) {}
	
	// rewrite the definitions from above to virtually inherit the Person class to solve issues with ambiguity
	
		class Employee:virtual public Person {
		public:
			Employee(string name, string ssid);
		private:
			string ssid;
	}
	
	class Student:virtual public Person {
		public:
			Student(string name, string sid);
		private:
			string sid;
	}
		
		
	// Now you can declare Workstudy without running into errors of ambiguity with multiple declarations
	// Base classes inherited virtually use only default constructors. To fix this create a mutator (below)
	
	class Person {
	public:
		Person(string name);
		void setname(string name);
	private:
		string name;
	}
	
	void setname(string name) {
		this-> name = name;
	}

	
	Workstudy::Workstrudy(string name, string ssid, string sid, string dept)
		:Student(name, sid), Employee(name, ssid), dept(dept) {
			Person::setname(name);
		}
		
		
// Polymorphism

class Person {
	public:
		virtual string whatami() {return "Person";}
}

class Employee:public Person {
	public:
		string whatami() {return "Employee";}
}

class Student:public Person {
	public:
		string whatami() {return "Student";}
}

// Static Binding
Person p("JS");
cout << p.whatami();

Student s("JP", "0009");
cout << s.whatami();

Person* q; 

// A pointer to a base class can point to any derived class

q = &s;
cout << q->whatami(); // prints Person unless you add virtual to the base class definition for the funtion whatami

//

cout << "What do you want to create?";
cout << "Enter 1 for person";
cout << "Enter 2 for Student";
cout << "Enter 3 for Employee";

// Assume person inputs 3

Person* p;
if (answer == 3) {
	cout << "Enter name ";
	cin >> name;
	cout << "Enter student id: ";
	cin >> studid;
	p = new student(name, studid);
	cout << p->whatami();
}

// 

class Player {
	public:
	private:
		Point position;
		bool isalive;
		string ip;
}

// 5 classes of different types of players

vector<Player*> v;
Play* p;
p = new Troll();
v.push_back(p);
p = new Wookie();
v.pushback(p);
p = new wigger();
v.pushback(p);

for (int i = 0; i < v.size(); i++) {
	v[i]-> displayview();
}

// Operators

class Pair {
	public:
		Pair(int a, int b);
		int get_x();
		int get_y();
		bool operator==(Pair p) const;
	private:
		int x;
		int y;
}

bool Pair::operator==(Pair p) {
	if (this->x != p.get_x()) {
		return false;
	}
	if (this->y != p.get_y()) {
		return false;
	}
	return true
}

int main() {
Pair a(10,10);
Pair b(10,20);

 if (a == b) { // == is like a boolean function
	cout << "Same pair";
}
}

// Static variables and functions

class BankAccount {
	public:
		double get_rate;
		static void change_rate(double new_rate);
	private:
		static double rate;
} // The word static is only used in the class definition

double BankAccount::rate = 0.02;

void BankAccount::change_rate(double new_rate) {
	rate = new_rate;
}

int main() {
	BankAccount b();
	BankAccount c();
	
	cout << b.get_rate();
	cout << c.get_rate();
}