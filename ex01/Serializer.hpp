#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

typedef struct {
  std::string data_string;
} Data;

class Serializer {
 private:
  Serializer();
  ~Serializer();
  Serializer(const Serializer &other);
  Serializer &operator=(const Serializer &other);

 public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif  // SERIALIZER_HPP
