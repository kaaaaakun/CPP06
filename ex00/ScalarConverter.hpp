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

  static void printAllType(float f);
  static void printAllType(double d);
  static void printAllType(int i);
  static void printAllType(char c);
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
