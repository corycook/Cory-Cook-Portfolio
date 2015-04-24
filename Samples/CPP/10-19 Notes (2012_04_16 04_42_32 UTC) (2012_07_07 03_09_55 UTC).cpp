/*	Vectors
		other container classes: deque, list
*/
	//vector declaration
		vector<circle> c;
			c.push_back(Circle(Point(0,0), 1)); //add circle Circle(Point(0,0),1) to c;
			cout << c.size(); //c.size = # of elements in c;
			c.pop_back(); //remove last element from c;
			c.clear(); //clears out the entire vector
/*
_read in grades(from file)
_calculate average
_print grades (put * next to those < average)
*/

#include <vectors>
#include <iostream>
#include <cmath>

double ave(const vector<int> &numbers) {
	int total = 0;
	for(i = 0; i < numbers.size();  i++) {
		total += numbers[i];
	}
	return (total*1.0)/numbers.size;
}

/*
	the ampersand above allows you to call-by-reference which does not copy the information to a seperate memory location but allows
	you to use the memory that is already written
	const allows you to call by reference without making any changes to the original memory location
*/

int main() {
	vector<int> grades; //declares the vector "grades" as int
	int temp; //declares a temporary holder for input
	cin >> temp; //inputs the first value
	while (cin.good()) {
		grades.push_back(temp); //writes the temp value to the vector
		cin >> temp; //gets the next value in the file
	}
	double average = ave(grades); //calls a function "ave" passing the vector argument "grades" to find the average
	
	for (int i = 0; i < grades.size(); i++) {
		if (grade[i] < average) {
			cout << grade[i] << "*" << endl;
		}
		else {
		cout << grade[i] << endl;
		}
	}
}


// g++ -o prog prog.cpp
// ./prog < input.txt > output.txt //creates output.txt or destroys & creates existing output.txt
// ./prog < input.txt >> output.txt //creates or appends to existing output.txt

class Bubbles {
	public:
		Bubbles();
		
		void drift(int dx, int dy);
		void blow(Circle bubble);
		void pop(Point center);
		void display();
	private:
		vector<Circle> c;
};

Bubbles::Bubbles(){}

void Bubbles::drift(int dx, int dy) {
	for (int i = 0; i < c.size; i++) {
		c[i].move(dx,dy);
	}
}

void Bubbles::blow(Circle bubble) {
	c.push_back(bubble);
}

void Bubbles::pop(Point center) {
	double centerx = center.get_x();
	double centery = center.get_y();
	for (int i=0; i < c.size; i++) {
		double cx = c[i].get_center().get_x();
		double cy = c[i].get_center().get_y();
		if (cx == centerx && cy == centery) {
			c[i] = c[c.size()-1];
			c.pop_back();
			return; // This only pops the first bubble that it comes to and then stops the function. w/o this all bubbles at point center will pop.
		}
	}
}

void Bubbles::dispaly() {
	for (int i = 0; i < c.size; i++) {
		cwin << c[i];
	}
}