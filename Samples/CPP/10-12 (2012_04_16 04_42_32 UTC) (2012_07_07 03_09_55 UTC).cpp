class Triangle
{
	public:
		Triangle (Line l1, Line l2, Line l3)
		void display();
		Line get_line1()
		{return l1;}
		Line get_line2()
		{return l2;}
		Line get_line3()
		{return l3;}
		void move(int dx, int dy);
		void mogrify();
	
	private:
		Line l1;
		Line l2;
		Line l3;
}

Triangle::Triangle(Line l1, Line l2, Line l3)
{
	/*	Good programming rule: 
		use the this-> when referring to attributes in member functions.
	*/
	this->l1 = l1;
	this->l2 = l2;
	this->l3 = l3;
}

void Triangle::display
{
	cwin << this->l1;
	cwin << this->l2;
	cwin << this->l3;
}

void Triangle::move(int dx, int dy)
{
	this->l1.move(dx,dy);
	this->l2.move(dx,dy);
	this->l3.move(dx,dy);
}

void Triangle::mogrify()
{
	this->move(-5.5);
}

ccc_win_main()
{
	Point a = cwin.get_mouse("Click");
	Point b = cwin.get_mouse("Click");
	Point c = cwin.get_mouse("Click");
	Triangle t(Line (a,b), Line (b,c), Line (c,a))
	t.mogrify();
	t.display();
	t.move(10,10);
	t.display();
}



//New Example

//Save each class into a .h (header) file
//Save each function (even sub functions of classes) into .cpp files
class CPU
{
	public:
		CPU(string mfg, double clock, string model);
		string get_mfg();
		double get_clock();
		void overclock(double newclock);
		
	private:
		string mfg;
		double clock;
		string model;
}

class Drive
{
	public:
		Drive(string, string, long)
		string get_model();
	private:
		string mfg;
		string model;
		long size;
}

Class Sys
{
	public:
	private:
		string mfg;
		string model;
}

#ifndef COMPUTER_H
#define COMPUTER_H //These two lines prevent errors caused by being called by multiple functions
Class Computer
{
	public:
		Computer(CPU proc, Sys board, Drive disk);
		
		CPU get_proc()
		{return this->proc;}
		double get_cpu_clock()
		{return this->proc.get_clock();}
		
	private:
		CPU proc;
		Sys board;
		Drive disk;
}
#endif //closes the ifndef COMPUTER_H

/*
	If the computer class is called before the CPU class then it will not compile.
	To fix this issue set up modules.
	1. Place the interface (class definition) in a file called (e.g. cpu.h)
	2. Place functions in cpu.cpp
		In the .cpp file we place: #include "cpu.h"
	g++ -o cpu cpu.cpp
			^^ <- Binary instructions for Class CPU
	computer.h
	computer.cpp
		#include "computer.h"
		#include "cpu.h"
		#include "sys.h"
		#include "drive.h"
		
	g++ -o computer computer.cpp
	g++ -o program computer.cpp cpu.cpp --> error caused by multiple #include "cpu.h"
*/