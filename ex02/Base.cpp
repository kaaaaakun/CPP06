#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base() { std::cout << "Base constructor" << std::endl; }
Base::~Base() { std::cout << "Base destructor" << std::endl; }
Base::Base(Base const &other) { *this = other; }
Base &Base::operator=(Base const &other) {
  (void)other;
  return *this;
}
