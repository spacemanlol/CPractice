#ifndef CADILLAC_H
#define CADILLAC_H
#include "oop.h"

class Cadillac:public Car {
	public:
		Cadillac(int price, int year, string model);
		int getPrice();
		~Cadillac();
};
#endif
