#include <iostream>
#include "ccc_win.h"

class CPU {
	interface
};

// Split files: cpu.h (interface) and cpu.cpp (functions)

class Drive {
};

// Split files: drive.h (interface) and drive.cpp (functions)

class Sys {
};

// Split files: sys.h (interface) and sys.cpp (functions)

class Computer {
	computer.h
	computer.cpp
};

/* 	to compile function sub-programs of classes g++ -c cpu.cpp
		-c means "just compile"
		this creates a file cpu.o
	g++ -o computer cpu.o
		this links the compiled cpu.o to the "computer" program
*/

// main.cpp
/*
	g++ -c cpu.cpp
		this goes into a cpp.o file
	g++ -c drive.cpp
		drive.o file
	g++ -c sys.cpp
		sys.o
	g++ -c computer.cpp
		computer.o
	g++ -c main.cpp
		main.o
		main.cpp should have includes for all of the above files. (#include "computer.h", etc.)
	
*/

#include "cpu.h"
#include "drive.h"
#include "sys.h"
#include "computer.h"

/* 	g++ -o computer cpu.o drive.o sys.o computer.o main.o
	each .cpp file (e.g. cpu.cpp) has to have an #include " .h" file
	(e.g #include "cpu.h")
	each.h file (e.g. cpu.h) has to have:
*/
#ifndef CPU_H
#DEFINE CPU_H
class CPU {
}
#endif

// This will ensure that the compiler will only use the first include of class.h

/*	make - program to compile programs
	make file can be anything but traditionally:
		Makefile or makefile
*/

// Makefile
computer: cpu.o drive.o sys.o computer.o main.o
/*tab*/	g++ -o computer cpu.o drive.o sys.o computer.o main.o
cpu.o: cpu.cpp
	g++ -c cpu.cpp
drive.o:
	g++ -c drive.cpp
sys.o: sys.cpp
	g++ -c sys.cpp
computer.o: computer.cpp
	g++ -c drive.cpp
main.o: main.cpp
	g++ -c main.cpp
	
/*	In order to now compile this Makefile
		make -f makefile
			if you leave off the -f makefile it will automatically 
			look for makefile of Makefile in the directory
		make -f makefile cpu.o
			this ignores everything except cpu.o
		make clean
			deletes all .o files
*/

// CHAPTER 6 VECTORS

/*	problem: read in a collection of exam scores and 
	print them out with an asterisk next to scores below average
*/

vector<int> scores;
// vector<int> scores(10); where 10 is the size of the vectors //This form is not used anymore.
scores.pushback(89); //creates an element in the first memory location(0) and assigns its value to 89
scores.pushback(91); //creates an element in the second location...
scores.pushback(82); //creates an element in the third location..

cout << score.size(); //outputs number of elements in the vector

scores.pop_back(); //deletes the last element in the vector series

// Vector functions (same as above):
vector<int> v;
v.push_back(x); //x and v are same type
v.pop_back(); // deletes last value
v.size; //returns size of the vector

#include <vector>
#include <iostream>
using namespace std;

/*	Without using namespace std;:
	v.pop_back(); becomes:
	v.vector::pop_back();
*/

int main() {
	vector<int> scores;
	int tscore;
	
	cin >> tscore;
	
	while(cin.good) {	//cin.good makes sure that the value was able to read in
		scores.push_back(tscore);
		cin >> tscore;
	}
	
	//importing the scores from a file called scores.txt that has a list of numbers
}

/*	g++ -o scores scores.cpp
	./scores
		this gets input from the keyboard
	./scores < scores.txt
		this gets input from the scores.txt file
	./scores < scores.txt > scores.dat
		this inputs from scores.txt and outputs to scores.dat
		
	For now this is the only way we can input and output files.. eventually we will learn about fstream library
*/