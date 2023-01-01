#include "Lexus.h"

Lexus::Lexus(int price, int year, string model){
	this->price = price;
	this->year = year;
	this->model = model;
}

int Lexus::getPrice(){
	return this->price;
}
