#include "C.hpp"

#include <iostream>

C::C() {}
C::C(const C &other) { (void)other; }
C::~C() {}
C &C::operator=(const C &other) {
  (void)other;
  return *this;
}
