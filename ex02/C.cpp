#include "C.hpp"

#include <iostream>

C::C() { std::cout << "C constructor" << std::endl; }
C::C(const C &other) { (void)other; }
C::~C() { std::cout << "C destructor" << std::endl; }
C &C::operator=(const C &other) {
  (void)other;
  return *this;
}
