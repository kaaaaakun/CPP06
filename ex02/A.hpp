#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class Base;

class A : public Base {
 public:
  A(){};
  A(const A &other) { (void)other; };
  ~A(){};
  A &operator=(const A &other) {
    (void)other;
    return *this;
  };
};

#endif
