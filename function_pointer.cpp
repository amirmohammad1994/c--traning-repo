// In the Name of God

#include <iostream>
#include <vector>

void exampleFunction() { std::cout << "example function." << std::endl; }
int factorial(int n) { return n == 0 ? 1 : factorial(n - 1) * n; }

void forEach(const std::vector<int>& values, void (*function)(int)) {
  for (int value : values) {
    function(value);
  }
}

void printValue(int value) { std::cout << value << std::endl; }
int main() {
  auto functionPtr = exampleFunction;
  functionPtr();

  // & is not necessary because of implicit conversion
  int (*functionPtr2)(int) = &factorial;
  std::cout << functionPtr2(4) << std::endl;

  typedef void (*exampleFunctionType)();
  exampleFunctionType exampleFunctionPtr = exampleFunction;
  exampleFunctionPtr();

  std::vector<int> values = {1, 2, 4, 5, 3};
  forEach(values, printValue);
  // lambda style
  forEach(values, [](int value) { std::cout << value << std::endl; });

  std::cin.get();
  return 0;
}