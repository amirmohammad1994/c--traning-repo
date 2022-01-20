// In the Name of God

#include <iostream>

template <typename T>
void print(T t) {
  std::cout << t << std::endl;
}

template <typename T, int N>
class Array {
 private:
  T m_Array[N];

 public:
  int getSize() { return N; }
};

// Compile errors just shown when use a template

int main() {
  print(10);
  print("Amir");
  print<float>(2.0f);

  Array<int, 100> array;
  std::cout << array.getSize() << std::endl;

  std::cin.get();
  return 0;
}