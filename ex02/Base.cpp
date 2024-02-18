#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base() { std::cout << "Base constructor" << std::endl; }
Base::~Base() { std::cout << "Base destructor" << std::endl; }

Base *Base::generate(void) {
  std::srand(std::time(NULL));
  int i = rand() % 3;
  if (i == 0) return new A;
  if (i == 1) return new B;
  return new C;
}

void Base::identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown" << std::endl;
}

void Base::identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "A" << std::endl;
    return;
  } catch (std::exception &e) {
  }
  try {
    B &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << "B" << std::endl;
    return;
  } catch (std::exception &e) {
  }
  try {
    C &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << "C" << std::endl;
    return;
  } catch (std::exception &e) {
  }
  std::cout << "Unknown" << std::endl;
}
