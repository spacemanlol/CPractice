#include "oop.h"
#include "Lexus.h"

int main(){
	Car a(2023, "Tesla");
	Lexus l(100000, 2023, "toyota");
	cout << a.getPrice() << endl;
	return 0;
}

