#include "B.hpp"

#include <iostream>

B::B() {}
B::B(const B &other) { (void)other; }
B::~B() {}
B &B::operator=(const B &other) {
  (void)other;
  return *this;
}
