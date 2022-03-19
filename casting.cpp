// In the Name of God

#include <iostream>

class Base {
 public:
  Base();
  ~Base();
};

class Derived : public Base {
 public:
  Derived();
  ~Derived();
};

class AnotherClass : public Base {
 public:
  AnotherClass();
  ~AnotherClass();
};

int main() {
  // implicit casting
  int a = 5;
  double value = a;
  std::cout << a << ", " << value << std::endl;

  double value2 = 3.14;
  int b = value2;
  std::cout << b << ", " << value2 << std::endl;

  // C-style cast
  double value3 = 5.25;
  double c = (int)value3 + 5.3;
  // double c = (int)(value3 + 5.3);
  std::cout << c << std::endl;
  // C++style cast
  // static_cast: compile time checking
  // dynamic_cast: run time checking
  // reinterpret_cast: type punning like
  double d = static_cast<int>(value3) + 5.3;

  //
  Derived* derived = new Derived();
  Base* base = derived;
  AnotherClass* anotherClass = dynamic_cast<AnotherClass*>(base);
 //


  return 0;
}