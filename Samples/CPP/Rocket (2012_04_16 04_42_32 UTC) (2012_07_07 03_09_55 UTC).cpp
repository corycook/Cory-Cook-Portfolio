// File: rocket.cpp
// By: Cory Cook
// Project: lab3

#include "ccc_win.h"

using namespace std;

// a simple rocket is represented by a Point which is the lower left
// corner of the rocket when displayed pointing up; The attributes
// also include a direction (string) having values "up", "down", "letf"
// and "right".

class Rocket
{
public:
  
  Rocket();  // Default constructor

  Rocket(Point loc);       // constructor where rocket always points up
  
  void display() const;  // accessor function, displays rocket

  void move(int dx, int dy);  // mutator function, moves rocket

  void direction(string newdirection);  // mutator function, changes direction

private:

  Point llc; // lower left corner, location of rocket when pointing up

  string direction; // this can be up, down, right or left

  void displayup(); // function used by display to draw the rocket pointing up

  void displaydown(); // function used by display to draw the rocket pointing down

  void displayright(); // function used by display to draw the rocket pointing right

  void displayleft(); // function used by display to draw the rocket pointing left 


};

// default; the number is 0 and the location is at (0,0);

Rocket::Rocket()
{
  this->llc = Point(0,0);
  direction="up";
}

// constructor of Rocket object with number num at Point loc;

Rocket::Rocket(Point loc)
{
	this->llc = loc
}

// accessor function: displays a rocket with lower left corner at 
// llc; the function determines the direction and calls the appropriate
// private display function.

void Rocket::display() const
{
//calls one of the private functions depending on direction
	if (direction == "left") {
		Rocket::displayleft();
	}
	elseif (direction == "right") {
		Rocket::displayright();
	}
	elseif (direction == "down") {
		Rocket::displaydown();
	}
	else {
		Rocket::displayup();
	}
}

void Rocket::move(int dx, int dy);
{
	this->llc = Point(llc.get_x() + dx, llc.get_y() + dy);
}

void Rocket::displayup();
{
	Point ulc(llc.get_x(), llc.get_y() + 20);
	Point top(llc.get_x() + 2.5, llc.get_y() + 25);
	Point urc(llc.get_x() + 5, llc.get_y() + 20);
	Point lrc(llc.get_x() + 5, llc.get_y());
	Line l(llc, ulc);
	Line ul(ulc, top);
	Line ur(top, urc);
	Line r(urc, lrc);
	Line b(lrc, llc);
	cwin << l << ul << ur << r << b;
}

void Rocket::displaydown();
{
}

void Rocket::displayright();
{
}

void Rocket::displayleft();
{
}

// main() function; 
// 

int ccc_win_main()
{
   cwin.coord(0,1000,1000,0);
   Rocket usa1(Point(250,10));
   Rocket usa2(Point(750,10));
   usa1.display();
   usa2.display();

  for (i = 0; i <= 1000; +=150)
    {
      usa1.move(0,i);
      usa2.move(0,i);
      usa1.display();
      usa2.display();
    }
      
  return 1;
}