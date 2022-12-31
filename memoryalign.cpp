#include "memoryalign.h"
#include <iostream>

using namespace std;

void testalign(){

	char a;
	char b;
	char c1;
	short d;
	int e;
	long l;
	double k;	
	A a1;
	B r;
	C c2;
	D d2;

	cout << "a = " << sizeof(a) << endl;
	cout << "d = " << sizeof(d) << endl;
	cout << "e = " << sizeof(e) << endl;
	cout << "l = " << sizeof(l) << endl;
	cout << "k = " << sizeof(k) << endl;
	cout << "b = " << sizeof(r) << endl;
	cout << "A = " << sizeof(a1) << endl;
	cout << "C = " << sizeof(c2) << endl;
	cout << "D = " << sizeof(d2) << endl;
}
