class Bubbles {
public:
	Bubbles{};
	void blow(circle b);
	void drift(int dx, int dy);
	void pop(Point p);
	void display();
private:
	vector<Circle> c;
};

int ccc_win_main() {
	Bubbles bubbly();
	bubbly.blow(Circle(Point(0,0),s));
	Point p = cwin.get_mouse("click on center");
	int r = cwin.get_int("enter the radius");
	bubly.blow(Circle(p,r));
	bubbly.drift(5,-5);
	bubbly.display();
	bubbly.drift(1,10);
	bubbly.pop(Point(6,5);
	bubbly.display();
}

// Parallel Vectors

/*
	Database
		-fields
		name	|	address	|	phone	|	studid
		John Sm	|	517 Lex	|	none	|	01			// This row is a record
	
	all together is called a file in database theory
	-fields
	-records are a collection of fields
	-files are collections of records
	-databases are collections of files
	
	simple database of names and email addresses
	
	names			|		email address
	Smith. John		|	johnsmith@gmail.com
	
	all saved in email file called email.txt
	
	read database
	add records
	delete records
	search records
*/

class EmailDB {
	public:
		EmailDB():
		void loadDB();
		string get_email(string n);
		void change_email(string n, string e);
		void add_email(string n, string e);
		void delete_email(string n);
		
	private:
		vector<string> name;
		vector<string> email;
};

Email::EmailDB() {}

void EmailDB::loadDB() {
	string t1, t2;
	cin >> t1 >> t2;
	while (cin.good()) {
		name.push_back(t1);
		email.push_back(t2);
		cin >> t1 >> t2;
	}
}

// g++ -o db db.cpp
// ./db < email.txt > emailout.txt

string EmailDB::get_email(string n) {
	for (int i = 0; i < name.size(); i++) {
		if (name[i] == n) {
		return email[i];
		}
	}
	return "none found";
}

void EmailDB::change_email(string n, string e) {
	for (int i = 0; i < name.size(); i++) {
		if (name[i] == n) {
		email[i] = e;
		return;
		}
	}
	return;
}

void EmailDB::delete_email(string n) {
	for (int i = 0; i < name.size(); i++) {
		if (name[i] == n) {
		name[i] = name[name.size() - 1]
		email[i] = email[email.size() - 1];
		name.pop_back;
		email.pop_back;
		return;
		}
	}
	return;
}

void EmailDB::add_email(string n, string e) {
	name.push_back(n);
	email.push_back(e);
}

int ccc_win_main() {
	EmialDB edb();
	edb.loadDB(); //read from email.txt
	string search = cwin.get_string("enter name to find email");
	string answer = edb.get_email(search);
	cwin << message(Point(0,0), answer);
	edb.delete_email(search);
}