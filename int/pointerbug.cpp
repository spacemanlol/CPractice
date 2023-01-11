#include <iostream>

void test1()
{
   int* p;
   *p = 10;
   std::cout << "int* p; *p = 10; --> p not point to any memory,segmention fault" << std::endl;
}

void test2()
{
  int* p = 0;
  *p = 10;
   std::cout << "int* p = 0; *p = 10; --> p not point to any memory,segmention fault" << std::endl;
}

void test3()
{
   int arr[] = { 10, 20};
   int* p = arr;
   ++*p;
   std::cout << "int arr[] = { 10, 20 };" << std::endl;
   std::cout << "Precedence of pre-increment and * is same but evaluation order is from right to left" << std::endl;
   std::cout << "++*p = " << *p << ", " << arr[0] << ", " << arr[1] << std::endl;
}

void test5()
{
   int arr[] = { 10, 20};
   int* p = arr;
   *++p;
   std::cout << "*++p = " << *p << ", " << arr[0] << ", " << arr[1] <<std::endl;
}

void test4()
{
   int arr[] = { 10, 20};
   int* p = arr;
   *p++;
   std::cout << "Precedence of post-increment is higher than *" << std::endl;
   std::cout << "*p++ = " << *p  << ", " << arr[0] << ", " << arr[1] <<std::endl;
}

int main()
{
   test3();
   test4();
   test5();

   std::cout << "int* p; *p = 10; --> p not point to any memory,segmention fault" << std::endl;
   std::cout << "int* p = 0; *p = 10; --> p not point to any memory,segmention fault" << std::endl;
   test1();
   test2();
}
