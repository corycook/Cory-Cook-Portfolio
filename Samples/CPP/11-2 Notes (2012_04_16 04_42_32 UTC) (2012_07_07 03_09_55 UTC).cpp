/*	Midterm
		-classes
		-vectors
		-pointers
*/

class Person {
	public:
		Person(string name);
		void changename(string new);
		string getname();
		
	private:
		string name;
}

class Employee:public Person { // This class inherits the properties of the Person class
	public:
		Employee(string name, string id);
		string getid();
		string changeid(string newid);
		
	private:
		string id;	
}

class Faculty:public Employee {
	public:
		Faculty(string name, string id, string rank);
	private:
		string rank;
}

Employee::Employee(string name, string id):Person(name) {
	this->id = id
}

Faculty::Faculty(string name, string id, string rank):Employee(name, id) {
	this->rank = rank;
}

int main() {
	Employee e1("Smith, John", "00567");
	cout << e1.getname();
	cout << e1.getid();
}