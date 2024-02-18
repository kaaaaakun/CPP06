#include "A.hpp"

#include <iostream>

A::A() {}
A::A(const A &other) { (void)other; }
A::~A() {}
A &A::operator=(const A &other) {
  (void)other;
  return *this;
}
