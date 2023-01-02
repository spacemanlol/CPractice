#include "Cadillac.h"

Cadillac::Cadillac(int price, int year, string model):Car(year, model){
	this->price = price;
	std::cout << "Cadillac constructor" << std::endl;
}

int Cadillac::getPrice(){
	return 3333;
	return this->price;
}

Cadillac::~Cadillac(){
	std::cout << "Cadillac Destructor" << endl;
}

