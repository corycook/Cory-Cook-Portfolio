/*	Object Oriented Programming
	- attributes
	- functions
		- constructors
		- accessors
		- mutators
	together they are a software package
*/

#include "ccc_win.h"
#include <iostream>
#include <cmath>
using namespace std;

int ccc_win_main()	{
	/*	Point class
		1. Point (x,y)
			x, y can be int, dbl, etc.
		2. p.get_x()
		2. p.get_y()
		3. p.move(dx,dy)
			dx,dy are numbers
		attributes:
			x: numbers
			y: numbers
	*/
	Point origin = Point (0,0);
	double x = origin.get_x();
	cout << x;
	//cout << origin; //IOSTREAM does not know what a point is and cannot output
	cwin << origin //Outputs origin to screen.
	/*	Line Class
		1. Line (p,q)
			p,q must be points
		2. l.get_start()
		2. l.get_end()
		3. l.move (Ax,dy)
			Ax,dy are numbers
	*/
	Line diag (origin, Point(5,5))
	Line diag2 (origin, origin.move (5,5))
	cwin << diag2;
	cwin << origin;
	/*	Circle Class
		1. Circle (p,r)
			p is point and r is any number
		2. c.get_center()
			returns point (center)
		2. c.get_radius()
			returns radius
		3. c.move(dx,dy)
	*/
	//Overloading - using 2 different types of input
	//Encapsulation - fuctions only accessible by other functions and not the user
	Circle k = Circle (-5,10);
	cwin << k;
	k.move (-80,40);
	cwin << k;
	Circle kk = Circle (Point(15,20),10);
	/*	Message Class
		1. message(p,s)
			p is point and s is message
		2. m.get_start()
			returns point
		2. m.get_text()
			returns message
		3. m.move(dx,dy)
	*/
	message m = message (Point(0,0), "This is the origin.");
	cwin << m;
	
	cwin,coord (0,5000,5000,0); //Sets the coordinate system according to the topleft most and bottomright most points
	
	string name = cwin.get_string(p); // p is promt, i.e. p = "get name"
	int i = cwin.get_int("enter age");
	double ss = cwin.get_double("Enter SS#");
	
	Point click = cwin.get_mouse("Please click somewhere");
	cout << click.get_x() << click.get_y();	
}