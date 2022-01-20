// In the Name of God

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

uint32_t s_AllocCount = 0;

void* operator new(size_t size) {
  s_AllocCount++;
  std::cout << "Allocating " << size << "bytes\n";
  return malloc(size);
}

void print_name(const std::string& name) { std::cout << name << std::endl; }
void print_name(const std::string_view& name) {
  std::cout << name << std::endl;
}

int main() {
  std::string name = "Amir Mohmammad Ohadi";

  print_name(name);
  std::cout << s_AllocCount << " allocations" << std::endl;

  // print_name("Amir Mohammad Ohadi2");
  // std::cout << s_AllocCount << " allocations" << std::endl;

  std::string firstName = name.substr(0, 14);
  std::string lastName = name.substr(15, 20);
  print_name(firstName);
  print_name(lastName);
  std::cout << s_AllocCount << " allocations" << std::endl;

  std::string_view firstName_view(name.c_str(), 13);
  std::string_view lastName_view(name.c_str() + 15, 5);
  print_name(firstName_view);
  print_name(lastName_view);
  std::cout << s_AllocCount << " allocations" << std::endl;

  std::cin.get();
  return 0;
}