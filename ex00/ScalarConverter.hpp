#ifndef SCALAR_CONVERT_HPP
#define SCALAR_CONVERT_HPP

#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>

class ScalarConverter {
 private:
  static bool isOnlyChar(std::string& testStr);
  static bool isValidnumber(std::string& testStr);
  static bool isConvertible(std::string& testStr);
  static void print_error();
  static char toChar(const std::string& str);

 public:
  static void convert(std::string str);
};

#endif
