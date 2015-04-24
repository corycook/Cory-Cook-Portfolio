/*	Cory Cook
	Lab 7
*/
#include <iostream>
#include <string>
using namespace std;

// Person
class Person {
	public:
		Person(string name, string address, string phone, string Email);
		
		string get_name();
		string get_address();
		string get_phone();
		string get_Email();
	private:
		string name;
		string address;
		string phone;
		string Email;
};

Person::Person(string name, string address, string phone, string Email):
name(name), address(address), phone(phone), Email(Email) {}

string Person::get_name() {
	return this->name;
}
string Person::get_address() {
	return this->address;
}
string Person::get_phone() {
	return this->phone;
}
string Person::get_Email() {
	return this->Email;
}


// Person -> Student
class Student:public Person {
	public:
		Student(string name, string address, string phone,
	string Email, string status);
		
		string get_status();
	private:
		string status;
};

Student::Student(string name, string address, string phone,
	string Email, string status):
	Person(name, address, phone, Email), status(status) {}

string Student::get_status() {
	return this->status;
}

// Person -> Student -> Employee
class Employee:public Student {
	public:
		Employee(string name, string address, string phone,
	string Email, string status, string office, string salary, string hire_date);
		
		string get_office();
		string get_salary();
		string get_hire_date();
	private:
		string office;
		string salary;
		string hire_date;
};

Employee::Employee(string name, string address, string phone,
	string Email, string status, string office, string salary, string hire_date):
	Student(name, address, phone, Email, status), office(office), salary(salary), hire_date(hire_date) {}

string Employee::get_office() {
	return this->office;
}
string Employee::get_salary() {
	return this->salary;
}
string Employee::get_hire_date() {
	return this->hire_date;
}

// Person -> Student -> Employee -> Faculty
class Faculty:public Employee {
	public:
		Faculty(string name, string address, string phone,
			string Email, string status, string office, string salary,
			string hire_date, string rank, string fstatus);
		
		string get_rank();
		string get_fstatus();
	private:
		string rank;
		string fstatus;
};

Faculty::Faculty(string name, string address, string phone,
	string Email, string status, string office, string salary,
	string hire_date, string rank, string fstatus):
	Employee(name, address, phone, Email, status, office, salary, hire_date), 
	rank(rank), fstatus(fstatus) {}

string Faculty::get_rank() {
	return this->rank;
}

string Faculty::get_fstatus() {
	return this->fstatus;
}

// Person -> Student -> Employee -> Faculty -> Staff
class Staff:public Faculty {
	public:
		Staff(string name, string address, string phone,
	string Email, string status, string office, string salary,
	string hire_date, string rank, string fstatus, string position);
		
		string get_position();
	private:
		string position;
};

Staff::Staff(string name, string address, string phone,
	string Email, string status, string office, string salary,
	string hire_date, string rank, string fstatus, string position):
	Faculty(name, address, phone, Email, status, office, salary, hire_date, rank, fstatus),
	position(position){}

string Staff::get_position() {
	return this->position;
}

int main() {
	Person per = Person("Cory", "2065 W College Ave", "760.552.5995", "cookc303@coyote.csusb.edu");
	Student stu = Student("Cory", "2065 W College Ave", "760.552.5995", "cookc303@coyote.csusb.edu", "Junior");
	Employee emp = Employee("Cory", "2065 W College Ave", "760.552.5995", "cookc303@coyote.csusb.edu", "Junior", "Physics", "$7,000", "11-10-2010");
	Faculty fac = Faculty("Cory", "2065 W College Ave", "760.552.5995", "cookc303@coyote.csusb.edu", "Junior", "Physics", "$7,000", "11-10-2010",
		"associate", "visiting");
	Staff sta = Staff("Cory", "2065 W College Ave", "760.552.5995", "cookc303@coyote.csusb.edu", "Junior", "Physics", "$7,000", "11-10-2010",
		"associate", "visiting", "lab assistant");
		
	cout << per.get_name() << endl;
	cout << per.get_address() << endl;
	cout << per.get_phone() << endl;
	cout << per.get_Email() << endl;
	cout << stu.get_status() << endl;
	cout << emp.get_office() << endl;
	cout << emp.get_salary() << endl;
	cout << emp.get_hire_date() << endl;
	cout << fac.get_rank() << endl;
	cout << fac.get_fstatus() << endl;
	cout << sta.get_position() << endl;
	
	system("pause");
}
