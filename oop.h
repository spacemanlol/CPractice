#include <iostream>
#include <string>
using namespace std;

class Car {
	private:
		int price;
		int year;
		string model;
	public:
		Car(int year, string model);
		int getPrice();
	
};
