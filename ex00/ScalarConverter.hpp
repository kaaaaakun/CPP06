#ifndef SCALAR_CONVERT_HPP
#define SCALAR_CONVERT_HPP

#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>

class ScalarConverter {
 private:
  ScalarConverter();
  ~ScalarConverter();
  ScalarConverter(const ScalarConverter& other);
  ScalarConverter& operator=(const ScalarConverter& other);

  template <typename T>
  static void printAllType(T value) {
    putToChar(static_cast<int>(value));
    std::cout << "Int   : " << static_cast<int>(value) << std::endl;
    std::cout << "Float : " << std::fixed << std::setprecision(5)
              << static_cast<float>(value) << "f" << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(5)
              << static_cast<double>(value) << std::endl;
  }

  static void printAllType(std::string str);
  static void hugeNumPrint(double d);

  static bool isOnlyChar(std::string& testStr);
  static bool isValidnumber(std::string& testStr);
  static bool isConvertible(std::string& testStr);
  static void printError();
  static void putToChar(int i);

 public:
  static void convert(std::string str);
};

#endif
