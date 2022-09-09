// In the Name of God

#include <array>
#include <iostream>

template <typename T, size_t S>
class Array {
 public:
  Array() {}

  constexpr size_t Size() const { return S; }

  T& operator[](const size_t& index) { return m_Data[index]; }
  const T& operator[] const(const size_t& index) { return m_Data[index]; }

  T* Data() { return m_Data; }

  const T* Data() const { return m_Data }

 private:
  T m_Data[S];
};

int main() {
  std::array<int, 10> collection;
  collection.size();
  for (int i : collection) {
    std::cout << i;
  }

  Array<int, 10> arr;
  std::cout << arr.Size();

  static_assert(arr.Size() <= 10, "Array is too big!");

  const auto& arrReference = arr;

  for (int i = 0; i < arrReference.Size(); i++) {
    // should be work!
    // std::cout << arrReference[i] << std::endl;
    // error!:
    // arrReference[i] = 1;
    arr[i] = i;
  }

  return 0;
}