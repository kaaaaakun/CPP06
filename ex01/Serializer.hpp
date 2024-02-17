#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

struct Data {
  std::string data_string;
};

class Serializer {
 private:
  Serializer();
  ~Serializer();
  Serializer(const Serializer &other) { (void)other; };
  Serializer &operator=(const Serializer &other) {
    (void)other;
    return *this;
  };

 public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif  // SERIALIZER_HPP
