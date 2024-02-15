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

void Base::identify(Base &p) { identify(&p); }
