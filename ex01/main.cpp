#include <iostream>
#include <sstream>

#include "Serializer.hpp"

int main(void) {
  Data data;
  data.data_string = "Hello world!";
  std::cout << "Data             : " << &data << " : " << data.data_string
            << std::endl;

  uintptr_t serialized = Serializer::serialize(&data);

  std::stringstream ss;
  ss << std::hex << serialized;  // 16進数に変換
  std::string hexadecimalNumber = ss.str();
  std::cout << "serialized       :   " << hexadecimalNumber << " / "
            << serialized << std::endl;

  Data *deserialized = Serializer::deserialize(serialized);
  std::cout << "Deserialized     : " << &deserialized << " : "
            << deserialized->data_string << std::endl;

  return (0);
}
