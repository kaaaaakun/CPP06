#include "A.hpp"

#include <iostream>

A::A() { std::cout << "A constructor" << std::endl; }
A::A(const A &other) { (void)other; }
A::~A() { std::cout << "A destructor" << std::endl; }
A &A::operator=(const A &other) {
  (void)other;
  return *this;
}
