#include <iostream>
using namespace std;

struct A{
	char a;
	char b;
//	char c;
	short d;
	int e;
	long l;
	double k;	

};


struct B{
	long l;
	double k;
	int e;
	short d;
	char a;
	char b;
//	char c;

};
// LESSON: this struct req 20 bytes, but struct size is 24 because struct needs to be memory aligned with the highest data member size
struct C { 
	char c;
	double d;
	int i;
};

// LESSON: this struct req 13 bytes, but struct size is 16 because struct needs to be memory aligned with the highest data member size
struct D {
	double d;
	int s;
	char c;
};

int main(){
	//LESSON 1: hello is a constant string literal it is not allowed to be assigned to non constant character-to-pointer (compilation error)
	// char* p = "HELLO";
	const char* p = "HELLO";
	char c;
	int i = 0;
	while((c = p[i++]) != '\0'){
		cout << c << endl;
	}
	// LESSON 2: char p1[] = "HELLO"; - this is not a string literal, this is a array of characters
	char p1[] = "HELLO";
	p1[1] = 'X';
 	i = 0;	
	while((c = p1[i++]) != '\0'){
		cout << c << endl;
	}
	// LESSON 3a int* -> pointer to integer
	// LESSON 3b int const * -> pointer to const integer
	// LESSON 3c int * const -> const pointer to int
	// LESSON int const * const -> const pointer to const int
	const char* p3 = "WORLD";
	cout << *p3 << endl;
	p3++;
	//p3[2] = 'Y';
	cout << "TEST" << endl;
	cout << *p3 << endl;
	int x = 10;
	int& y = x;
       	y = 11;
	cout << x << endl;
	int x1 = 12;
	int z[] = {1,2,3};
	cout << z << " " << z[0] << endl;
	cout << z << " " << z[1] << endl;
	int* m = new int[5]{1,2,3,4,5};
	cout << m << " " << *m << endl;
	m++;
	cout << m << " " << *m << endl;
	// LESSON 4: difference between pointer and reference - reference cannot be reassigned, while a pointer can - reference cannot be unassigned, while a pointer can - at different times a pointer can point to different memory, wheras a reference always references the original variable.
	//int& y1;
	
	int* y2 = &x1; 
	int& y3 = x1;
	y2 =  &y;
        //y3 = &y;
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
	return 0;
}
