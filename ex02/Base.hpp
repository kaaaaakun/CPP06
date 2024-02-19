#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class Base {
 public:
  Base();
  virtual ~Base();
  Base(Base const &other);
  Base &operator=(Base const &other);
};

#endif
