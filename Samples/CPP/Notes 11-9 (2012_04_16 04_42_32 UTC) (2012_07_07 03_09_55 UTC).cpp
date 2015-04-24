/*	Cory Cook
	Notes 11-9
*/

class Engine {
	public:
		Engine(string ename, string size);
		
		string get_ename();
		string get_size();
	private:
		string ename;
		string size;
}

class Radio {
	public:
		Radio(string brand, string serial);
		
		string get_brand;
		string get_serial;
	private:
		string brand;
		string serial;
}

class Car:public Engine, public Radio {
	public:
		Car(string make, string model, string year, string ename, string size, string brand, string serial);
		
		string get_make();
	private:
		string make;
		string model;
		string year;
}

Car::Car(string make, string model, string year, string ename, string size, string brand, string serial):
	Engine(ename, size), Radio(brand, serial), make(make), model(model), year(year) {}
	
// or

Car::Car(string make, string model, string year, string ename, string size, string brand, string serial):
	Engine(ename, size), Radio(brand, serial) {
		this->make = make;
		this->model = model;
		this->year = year;
}