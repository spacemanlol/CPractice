#include "../OOP/Cadillac.h"

int main(){
	//LESSON - Memory creation happens in 2 stages, first it calculates the size of the object, and the proceeds to reserve that many bytes within the memory. Next, it instantiates the object and initialize that value to that memory.	
	Cadillac* c = new Cadillac(42000, 2023, "SRX");
	std::cout << c->getPrice() << std::endl;
	delete c;
	int* a1 = new int[10];
	std::cout << a1[0] << std::endl;
	std::cout << a1[5] << std::endl;
	std::cout << a1[9] << std::endl;
	//LESSON whenever you create multiple items in the heap, you need to use [] in order to properly delete the array. - if you don't use [], it will only delete the first item.
	delete [] a1;
	int* a2 = new int;
	delete a2;
	//LESSON you cannot create an Array of objects without a default contructor on the object.
	//Cadillac* c1 = new Cadillac[10];
	void* v = malloc(10); 
	char* c2 = (char*)v;
	free(v);
	void* v1 = calloc(10, sizeof(Cadillac));
	Cadillac* cad = (Cadillac*)v1;
	std::cout << cad->getPrice() <<std::endl;
	free(v1);
	
	return 0;
}
