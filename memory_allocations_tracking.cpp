// In the Name of God

#include <iostream>
#include <memory>

struct AllocationMetrics {
  uint32_t allocated = 0;
  uint32_t freed = 0;
  uint32_t totalUsage() { return allocated - freed; }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size) {
  s_AllocationMetrics.allocated += size;
  std::cout << "allocating " << size << " bytes" << std::endl;
  return malloc(size);
}

void operator delete(void* memory, size_t size) {
  s_AllocationMetrics.freed += size;
  std::cout << "deallocating " << size << " bytes" << std::endl;
  free(memory);
}

struct Object {
  int x, y, z;
};

int main() {
  Object* object = new Object;
  std::string str = "Amir";
  { std::unique_ptr<Object> u_obj = std::make_unique<Object>(); }
  std::cout << s_AllocationMetrics.totalUsage() << std::endl;
  delete object;
  std::cin.get();
  return 0;
}