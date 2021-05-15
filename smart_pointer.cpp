// In the Name of God

#include <iostream>
#include <memory>

class Entity {
 public:
  Entity() { std::cout << "entity is created." << std::endl; };
  ~Entity() {
    std::cout << "entity is destroyed." << std::endl
              << "------------------------------------------" << std::endl;
  }
  void print() { std::cout << "this is entity" << std::endl; }
};

int main() {
  {
    std::shared_ptr<Entity> pEntity2;
    std::unique_ptr<Entity> entityPtr = std::make_unique<Entity>();
    {
      std::unique_ptr<Entity> entityPtr2(new Entity());
      entityPtr2->print();
      std::shared_ptr<Entity> pEntity1 = std::make_shared<Entity>();
      pEntity2 = pEntity1;
      // weak pointer does not inc counter
      std::weak_ptr<Entity> wpEntity = pEntity1;
    }
  }

  std::cin.get();
  return 0;
}