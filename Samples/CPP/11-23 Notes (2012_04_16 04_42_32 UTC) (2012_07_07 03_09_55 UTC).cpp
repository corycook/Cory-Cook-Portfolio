//Streams (I/O)
#include <fstream>
/*
	fstream
		ifstream - input
		ofstream - output
		fstream - both
*/

int main() {
	ofstream outfile
	outfile.open("out.txt");

	for (int i = 2; i <= 1000; i += 2) {
		outfile << i << endl;
	}

	outfile.close();
}

void filecopy(string file1, string file2) {
	// This copies file1 to file2
	// Hope file2 doesn't exist 
	ifstream ifile;
	ifile.open(file1.c_str());
	ofstream ofile;
	ofile.open(file2.c_str());
	
	/*	get function
		char x = cin.get(); or cin.get(x);
		gets(inputs) 1 character from file or cin
	*/
	
	char x = ifile.get();
	while (ifile.good()) {
		ofile << x;
		ifile >> x;
	} // ends at eof character
	
	ifile.close();
	ofile.close();
}

/*
	infile.good() - no flags set
	infile.bad() - some flags set
	infile.eof() - eof is encountered
	infile.fail() - something bad has happened
	infile.clear() - clears flags
*/

string line;
getline(ifile, line);

/*	Database
	column(field) - unit of data (string, int)
	row(record) - collection of rows
	table(file) - collection of rows
	database - collection of tables
	
	eg.
	student_name	hwtotal	midterm	final
	Smith,John		70		84		88
	string			int		int		int
	
	Necessary database operations:
	1. add record
	2. delete record
	3. find record
*/

class Srecord {
	Srecord(string n, int h, int m, int f);
	string get_name();
	int get_hwtotal();
	
	private:
		string name;
		int hwtotal;
		int mid;
		int final;
}

class Stable {
	Stable(string filename);
	void addrecord(Srecord s);
	void delrecord(string name);
	Srecord find(string name);
	
	private:
		vector<Srecord> table;
		string filename;
		void write();
}

Stable::Stable(string filename) {
	this->filename = filename;
	Srecord s;
	string name;
	int hwtotal, mid, final;
	ifstream infile;
	infile.open(this->filename.c_str());
	infile >> name >> hwtotal >> mid >> final;
	while(infile.good()) {
		this->table.push_back(Srecord(name, hwtotal, mid, final));
		infile >> name >> hwtotal >> mid >> final;
	}
	infile.close();
}

void Stable::write() {
	ofstream outfile;
	outfile.open(filename.c_str());
	for (int i = 0; i < table.size(); i++) {
		outfile	<< table[i].get_name()
				<< table[i].get_hwtotal()
				<< table[i].get_mid()
				<< table[i].get_final()
				<< endl;
	}
	outfile.close();
}

void delrecord() {}
void addrecord() {}
