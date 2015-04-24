/*
	FUNCTIONS
	CLASSES
*/

double getbalance(double balance, double rate, int years) // to call by reference just add & i.e. int&years
	{
		double factor = 1;
		for(int i=1; i<=years; i++)
		{	
			factor *= (1+rate/100);
		}
		rate = 0;
		return balance * factor;
	}

int main()
{
	double balance, rate;
	int years;
	cout << "enter balance, rate, and years";
	cin >> balance >> rate >> years;
	cout << "new balance = " << getbalance(balance,rate,years);
	cout << "rate = " << rate;
}

// Write a function to accept two points and return the distance between them.

#include <cmath>
double dist(Point x, Point y)
{
	double x1 = x.get_x();
	double x2 = x.get_y();
	double y1 = y.get_x();
	double y2 = y.get_y();
	double d = sqrt(sqr(x1-y1)+sqr(x2-y2)); //be sure to include cmath for sqr and sqrt
	return d;
}

#include "ccc_win.h"
int ccc_win_main()
{
	/*Output a circle and ask a user to click in the circle
	if click is in circle clear the screen; otherwise, output missed.
	*/
	
	cwin << Circle(Point(10,10), 7;
	Point click = cwin.get_mouse("click in circle");
	if (dist(click, Point (10,10) <= 7)) {
		cwin.clr();
	}
	else {
		cwin << Message (click, "miss");
	}
}

int ccc_win_main()
{	
	/*Output a circle and ask a user to click in the circle
	if click is in circle clear the screen; otherwise, output missed.
	*/
	Point center = Point(10,10);
	double radius = 7;
	
	cwin << Circle(center, radius);
	Point click = cwin.get_mouse("click in circle");
	if (dist(click, center) <= radius) {
		cwin.clr();
	}
	else {
		cwin << Message (click, "miss");
	}
}

// CLASSES
/*
	Class (object)
		attributes
		functions (methods)
			cunstructor
			accessor
			mutator
*/

class Clock {
	public:
		//constructors
		Clock();
		Clock(int h, int m, int s);
		//
		int get_hours();
		int get_minutes();
		int get_seconds();
		void tick();
		void addseconds(int s);
		
	private:
		int hours;
		int minutes;
		int seconds
};

Clock::Clock() {
	hours = 0;
	minutes = 0;
	seconds = 0;
}

Clock::Clock(int h, int m, int s) {
	hours = h;
	minutes = m;
	seconds = s;
}

int Clock::get_hours() {
	return hours;
}

int Clock::get_minutes() {
	return minutes;
}

int Clock::get_seconds() {
	return seconds;
}

void Clock::tick() {
	seconds = seconds + 1;
	if (seconds == 60) {
		seconds = 0;
		minutes++;
	}
	if (minutes == 60) {
		minutes = 0;
		hours++;
	}
	if (hours == 13) {
		hours = 1;
	}
}

void Clock::addseconds(int s) {
	for (int i=1; i <= s; i++) {
	tick(); // Tick is applied to the object passed for addseconds
	}
}

int main() {
	Clock c = Clock(12,0,0);
	Clock end(1,15,0);
	c.tick();
	cout << c.get_hours();
	c.addseconds(4500);
	cout << c.gethours() << c.getminutes;
}