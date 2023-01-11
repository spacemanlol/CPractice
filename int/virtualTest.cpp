#include <iostream>

class A
{
  public:
  A()
  {
    std::cout << "A constructor" << std::endl;
  }

  virtual ~A()
  {
    std::cout << "A destructor" << std::endl;
  }
};

class B: public A
{
  public:
  B()
  {
    std::cout << "B constructor" << std::endl;
  }

 ~B()
  {
    std::cout << "B destructor" << std::endl;
  }
};

class C
{
  public:
  C()
  {
    std::cout << "C constructor" << std::endl;
  }

  ~C()
  {
    std::cout << "C destructor" << std::endl;
  }
};


class D: public C
{
  public:
  D()
  {
    std::cout << "D constructor" << std::endl;
  }

  virtual ~D()
  {
    std::cout << "D destructor" << std::endl;
  }
};

class E
{
  public:
  E()
  {
    std::cout << "E constructor" << std::endl;
  }
  virtual void print()
  {
    std::cout << "E print()" << std::endl;
  }
  ~E()
  {
    std::cout << "E destructor" << std::endl;
  }
};


class F: public E
{
  public:
  F()
  {
    std::cout << "F constructor" << std::endl;
  }

  virtual ~F()
  {
    std::cout << "F destructor" << std::endl;
  }
};


int main()
{
  // a will have virtual pointer and b will inherit the virtual pointer because A has virtual method destructor
  A* a = new B();
  delete a;

  // D will have virtual pointer but C will not  have virtual pointer, so when D casted to C, c has no access to virtual pointer so deleting C will not call D's destructor
  C* c = new D();
  delete c;

  // even though E has virtual method (but not in destructor) and F has virtual destructor (but not in E)
  // virtual pointer of E pointed to virtual table of E does not have entry for F's destructor
  // to  be available of derived class method using base class method, virtual should be declated in base class
  E* e = new F();
  delete e;
  return 0;

}
//  output
//A constructor
//B constructor
//B destructor
//A destructor

//C constructor
//D constructor
//C destructor

//E constructor
//F constructor
//E destructor
