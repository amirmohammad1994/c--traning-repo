// In the Name of God

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

void forEach(const std::vector<int>& values,
             const std::function<void(int)>& func) {
  for (int value : values) {
    func(value);
  }
}

int main() {
  std::vector<int> values = {2, 4, 5, 1, 3};

  auto it = std::find_if(values.begin(), values.end(),
                         [](int value) { return value > 3; });
  std::cout << *it << std::endl << "----------------------" << std::endl;

  auto lambda = [](int value) { std::cout << value << std::endl; };
  forEach(values, lambda);
  std::cin.get();
  return 0;
}