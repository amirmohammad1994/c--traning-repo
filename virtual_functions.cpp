// In the Name of God

#include <iostream>

using namespace std;

class Entity {
 public:
  virtual std::string getName() { return "Entity"; }
};

class Player : public Entity {
 public:
  Player(const std::string& name) : m_name(name){};
  std::string getName() override { return m_name; }

 private:
  std::string m_name;
};

int main() {
  Entity* entity = new Entity();
  std::cout << entity->getName() << std::endl;

  Player* player = new Player("Amir");
  std::cout << player->getName() << std::endl;

  Entity* player2 = new Player("Mohammad");
  std::cout << player2->getName() << std::endl;

  delete entity;
  delete player;
  delete player2;
  std::cin.get();
  return 0;
}