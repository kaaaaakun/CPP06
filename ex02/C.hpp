#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class Base;

class C : public Base {
 public:
  C(){};
  C(const C &other) { (void)other; };
  ~C(){};
  C &operator=(const C &other) {
    (void)other;
    return *this;
  };
};

#endif
