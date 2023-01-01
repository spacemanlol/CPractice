#include "oop.h"

Car::Car(int year, string model){
	this->year = year;
	this->model = model;
	this->price = 15000;
}

int Car::getPrice(){
	return this->price;
}

