#include "B.hpp"

#include <iostream>

B::B() { std::cout << "B constructor" << std::endl; }
B::B(const B &other) { (void)other; }
B::~B() { std::cout << "B destructor" << std::endl; }
B &B::operator=(const B &other) {
  (void)other;
  return *this;
}
