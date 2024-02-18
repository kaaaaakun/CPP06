#include <iostream>
#include <sstream>

#include "Base.hpp"

void genABC() {
  std::cout << "---- gen ABC ---" << std::endl;
  Base* base = Base::generate();
  std::cout << "ptr : ";
  base->identify(*base);
  std::cout << "ref : ";
  base->identify(base);
  delete base;
}

int main() {
  genABC();
  return 0;
}
