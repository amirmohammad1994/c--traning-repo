// In the Name of God

#include <iostream>

struct Vector2 {
  float x, y;
  Vector2(float x, float y) : x(x), y(y) {}
  Vector2() { x = y = 0.0f; }
  Vector2 operator+(const Vector2& v) const {
    return Vector2(x + v.x, y + v.y);
  }
  Vector2 operator*(float s) const { return Vector2(x * s, y * s); }
  bool operator==(const Vector2& v) const { return x == v.x && y == v.y; }
  bool operator!=(const Vector2& v) const { return x != v.x || y != v.y; }
};

std::ostream& operator<<(std::ostream& stream, const Vector2& v) {
  stream << v.x << ", " << v.y;
}

int main() {
  Vector2 v1(1.0f, 2.0f), v2(0.0f, 1.0f), v3;
  v3 = (v1 + v2) * 2;
  std::cout << v3 << std::endl;
  std::cout << (v1 == v2) << std::endl;
  std::cout << (v3 != v2) << std::endl;
  std::cout << std::cin.get();
  return 0;
}