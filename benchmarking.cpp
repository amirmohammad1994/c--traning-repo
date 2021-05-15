// In the Name of God

#include <array>
#include <chrono>
#include <iostream>
#include <memory>

class Timer {
 public:
  Timer() { m_StartTimePoint = std::chrono::high_resolution_clock::now(); }
  ~Timer() { stop(); }

 private:
  std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
  void stop() {
    auto endTimePoint = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(
                     m_StartTimePoint)
                     .time_since_epoch()
                     .count();
    auto end =
        std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint)
            .time_since_epoch()
            .count();
    double ms = (end - start) * 0.001;
    std::cout << ms << " ms" << std::endl;
  }
};

struct Vector2 {
  float x;
  float y;
};

int main() {
  int value = 0;
  {
    Timer timer;
    for (int i = 0; i < 1000000000; i++) {
      value += 2;
    }
  }
  std::cout << value << std::endl;

  std::cout << "make shared" << std::endl;
  {
    std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
    Timer timer;
    for (int i = 0; i < 1000; i++) {
      sharedPtrs[i] = std::make_shared<Vector2>();
    }
  }

  //   std::cout << "new shared" << std::endl;
  //   {
  //     std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
  //     Timer timer;
  //     for (int i = 0; i < 1000; i++) {
  //       sharedPtrs[i] = std::make_shared<Vector2>(new Vector2);
  //     }
  //   }

  std::cout << "make unique" << std::endl;
  {
    std::array<std::unique_ptr<Vector2>, 1000> uniquePtrs;
    Timer timer;
    for (int i = 0; i < 1000; i++) {
      uniquePtrs[i] = std::make_unique<Vector2>();
    }
  }

  std::cin.get();
  return 0;
}