#ifndef OOP_H 
#define OOP_H
#include <iostream>
#include <string>
using namespace std;

class Car {
	private:
	public:
		Car(int year, string model);
		// LESSON default consstructor is the constructor you can call without passing any arguments even thought it might have default paramters.
//		Car(int year = 2000);
		virtual	int getPrice();
		~Car();
	protected:
		int price;
		int year;
		string model;
};
#endif
