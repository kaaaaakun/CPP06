#include <iostream>
#include <sstream>

#include "Serializer.hpp"

int main(void) {
  Data data;
  data.data_string = "Hello world!";
  std::cout << "Data             : " << &data << " : " << data.data_string
            << std::endl;

  uintptr_t serialized = Serializer::serialize(&data);
  std::cout << "--- serialized ---" << std::endl;

  std::stringstream ss;
  ss << std::hex << serialized;
  std::string hexadecimalNumber = ss.str();
  std::cout << "serialized(dec)  : " << serialized << std::endl;
  std::cout << "serialized(hex)  :   " << hexadecimalNumber << std::endl;

  Data *deserialized = Serializer::deserialize(serialized);
  std::cout << "--- deserialized ---" << std::endl;
  std::cout << "Deserialized     : " << deserialized << " : "
            << deserialized->data_string << std::endl;

  return (0);
}
