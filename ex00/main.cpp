#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <test string>" << std::endl;
    return 1;
  }
  ScalarConverter::convert(argv[1]);

  // std::cout << "\nエラーの文字列---------------" << std::endl;
  // ScalarConverter::convert("");
  // ScalarConverter::convert("aaaaaa");
  // ScalarConverter::convert("1.1.1");
  // ScalarConverter::convert("");
  // ScalarConverter::convert(".11");

  // std::cout << "\n nan inf系------------------------" << std::endl;
  // ScalarConverter::convert("nan");
  // ScalarConverter::convert("-nan");
  // ScalarConverter::convert("inf");
  // ScalarConverter::convert("+inf");
  // ScalarConverter::convert("-inf");
  // ScalarConverter::convert("1234567890123456789012345678901234567890");

  // std::cout << "\n正常の文字列----------------------------" << std::endl;
  // ScalarConverter::convert("a");
  // ScalarConverter::convert("1");
  // ScalarConverter::convert("-10");
  // ScalarConverter::convert("10");
  // ScalarConverter::convert("2147483647");
  // ScalarConverter::convert("-2147483648");
  // ScalarConverter::convert("123456789012345678901234567890");
  // ScalarConverter::convert("42.0f");
  // ScalarConverter::convert("42.0F");
  // ScalarConverter::convert("42.0");
  // ScalarConverter::convert("42.1");
  return 0;
}