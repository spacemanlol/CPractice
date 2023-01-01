#ifndef LEXUS_H
#define LEXUS_H
#include "oop.h"

class Lexus:Car{
	public:
		Lexus(int price, int year, string model);
		int getPrice();
		~Lexus();
};
#endif
