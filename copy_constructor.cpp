// In the Name of God

#include <cstring>
#include <iostream>

struct Vector2 {
  float x;
  float y;
};

class String {
 private:
  char* m_buffer;
  unsigned int m_size;

 public:
  String(const char* string) {
    m_size = strlen(string);
    m_buffer = new char[m_size + 1];
    std::memcpy(m_buffer, string, m_size);
    m_buffer[m_size] = 0;
  }
  String(const String& other) : m_size(other.m_size) {
    m_buffer = new char[m_size + 1];
    std::memcpy(m_buffer, other.m_buffer, m_size + 1);
  };
  // copy not allowed
  // String (const String& other) = delete;

  ~String() {
    std::cout << "string " << *this << " deleted!" << std::endl;
    delete[] m_buffer;
  }
  char* getBuffer() const { return m_buffer; }
  friend std::ostream& operator<<(std::ostream& stream, const String& string);
  char& operator[](int index) { return m_buffer[index]; }
};

// if pass by value copy constructor is called.
void printString(const String& string){
  std::cout << string.getBuffer();
}

std::ostream& operator<<(std::ostream& stream, const String& string) {
  stream << string.m_buffer;
  return stream;
}

int main() {
  Vector2 a = {2, 3};
  Vector2 b;  // copy the value

  Vector2* c = new Vector2();  // copy the pointer
  Vector2* d = c;

  {
    String string = "Amir";
    String string2 = string;
    string2[2] = 'a';

    std::cout << string << std::endl;
    std::cout << string2 << std::endl;
  }
  std::cin.get();
  return 0;
}