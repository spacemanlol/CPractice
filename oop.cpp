#include "oop.h"
//Car::Car(){
//	std::cout << "car default constructor" << endl;
//}

Car::Car(int year, string model){
	this->year = year;
	this->model = model;
	this->price = 15000;
	std::cout << "car car" << endl;
}

int Car::getPrice(){
//	return this->price;
	return 1111;
}

Car::~Car(){
	std::cout << "Car Destructor" << std::endl;
}
