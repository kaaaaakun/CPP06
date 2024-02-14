#include <iostream>

int main() {
  std::cout << std::stof("inf") << std::endl;
  std::cout << std::stof("-inf") << std::endl;
  std::cout << std::stof("nan") << std::endl;
  std::cout << std::stof("-nan") << std::endl;
  try {
    std::cout << std::stof("INF") << std::endl;
    std::cout << std::stof("AAAA") << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
