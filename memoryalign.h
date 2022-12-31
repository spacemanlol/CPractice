
void testalign();
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
