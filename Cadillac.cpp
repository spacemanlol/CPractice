#include "Cadillac.h"

Cadillac::Cadillac(int price, int year, string model){
	this->price = price;
	this->year = year;
	this->model = model;
}

int Cadillac::getPrice(){
	return this->price;
}
