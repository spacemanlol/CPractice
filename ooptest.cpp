#include "oop.h"
#include "Lexus.h"
#include "Cadillac.h"

int main(){
	Car a(2023, "Tesla");
	cout << a.getPrice() << endl;
	Lexus l(100000, 2023, "toyota");
	cout << l.getPrice() << endl;
	Cadillac c(69000, 2019, "cad");
	cout << c.getPrice() << endl;
	Car c1 = c;

	cout << c1.getPrice() << endl;
	Cadillac* c2 = new Cadillac(42000, 2018, "cad2");
	Car* c3 = c2;		
	cout << c2->getPrice() << endl;
	cout << c3->getPrice() << endl;
	return 0;
}

