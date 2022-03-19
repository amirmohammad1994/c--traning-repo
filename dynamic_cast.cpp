// In the Name of God

#include <iostream>
#include <string>

class Entity {
 public:
  virtual void method();
};

class Player : public Entity {
 public:
};

class Enemy : public Entity {
 public:
};

int main() {
  Player* player = new Player();
  // implicit cast
  Entity* entity = player;
  Entity* entity2 = new Enemy();

  // player2 will be an actual player!
  Player* player2 = dynamic_cast<Player*>(entity);
  if (player2) {
  }
  // player3 will be null!
  Player* player3 = dynamic_cast<Player*>(entity2);
  if (player3) {
  }
  // warning: dynamic casting uses RTTI and incurs a cost!
  return 0;
}