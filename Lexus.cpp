#include "Lexus.h"

Lexus::Lexus(int price, int year, string model):Car(year, model){
	this->price = price;
	std::cout << "lexus constructor" <<std::endl;
}

int Lexus::getPrice(){
	return 2222;
	return this->price;
}

Lexus::~Lexus(){
	std::cout << "Lexus Destructor" << endl;
}

