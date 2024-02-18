#include "ScalarConverter.hpp"

#include <stdexcept>

// Canonical Form
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
  (void)other;
  return *this;
}

void ScalarConverter::putToChar(int i) {
  if (std::isprint(i) == 0) {
    std::cout << "Char  : Non displayable" << std::endl;
  } else {
    std::cout << "Char  : '" << static_cast<char>(i) << "'" << std::endl;
  }
}

void ScalarConverter::printAllType(float f) {
  putToChar(static_cast<int>(f));
  std::cout << "Int   : " << static_cast<int>(f) << std::endl;
  std::cout << "Float : " << std::fixed << std::setprecision(1) << f << "f"
            << std::endl;
  std::cout << "Double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(f) << std::endl;
}

void ScalarConverter::printAllType(double d) {
  putToChar(static_cast<int>(d));
  std::cout << "Int   : " << static_cast<int>(d) << std::endl;
  std::cout << "Float : " << std::fixed << std::setprecision(1)
            << static_cast<float>(d) << "f" << std::endl;
  std::cout << "Double: " << std::fixed << std::setprecision(1) << d
            << std::endl;
}

void ScalarConverter::printAllType(int i) {
  putToChar(static_cast<int>(i));
  std::cout << "Int   : " << i << std::endl;
  std::cout << "Float : " << std::fixed << std::setprecision(1)
            << static_cast<float>(i) << "f" << std::endl;
  std::cout << "Double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(i) << std::endl;
}

void ScalarConverter::printAllType(char c) {
  std::cout << "Char  : '" << c << "'" << std::endl;
  std::cout << "Int   : " << static_cast<int>(c) << std::endl;
  std::cout << "Float : " << std::fixed << std::setprecision(1)
            << static_cast<float>(c) << "f" << std::endl;
  std::cout << "Double: " << std::fixed << std::setprecision(1)
            << static_cast<double>(c) << std::endl;
}

void ScalarConverter::printAllType(std::string str) {
  std::cout << "Char  : impossible" << std::endl;
  std::cout << "Int   : impossible" << std::endl;
  std::cout << "Float : " << std::fixed << std::setprecision(1) << str << "f"
            << std::endl;
  std::cout << "Double: " << std::fixed << std::setprecision(1) << str
            << std::endl;
}

void ScalarConverter::printError() {
  std::cerr << "Char  : impossible" << std::endl;
  std::cerr << "Int   : impossible" << std::endl;
  std::cerr << "Float : impossible" << std::endl;
  std::cerr << "Double: impossible" << std::endl;
}

void ScalarConverter::hugeNumPrint(double d) {
  std::cout << "Char  : impossible" << std::endl;
  std::cout << "Int   : impossible" << std::endl;
  std::cout << "Float : " << std::fixed << std::setprecision(1)
            << static_cast<float>(d) << "f" << std::endl;
  std::cout << "Double: " << std::fixed << std::setprecision(1) << d
            << std::endl;
}

void ScalarConverter::convert(std::string string) {
  std::cout << "\nstring: " << string << std::endl;
  if (string.empty()) {
    printError();
    return;
  }
  // 文字列+1文字
  else if (string.size() == 1 && !isdigit(string[0])) {
    printAllType(string[0]);
    return;
  }
  // nan -nan inf -inf
  else if (string == "nan" || string == "-nan" || string == "+nan" ||
           string == "nanf" || string == "-nanf" || string == "+nanf" ||
           string == "inf" || string == "-inf" || string == "+inf" ||
           string == "inff" || string == "-inff" || string == "+inff") {
    printAllType(string);
    return;
  }
  // string error or number + string
  unsigned int i = 0;
  bool isdot = false;
  for (; i < string.length(); i++) {
    // 数字以外の時
    if (isdigit(string[i]) == 0) {
      // 符号の時
      if (i == 0 && (string[i] == '-' || string[i] == '+')) {
        continue;
      }
      // 小数点の時
      if (i != 0 && string[i] == '.' && isdot == false &&
          i != string.length() - 1) {
        isdot = true;
        continue;
      }
      if ((string[i] == 'f' || string[i] == 'F') && i == string.length() - 1) {
        printAllType(std::stof(string));
        return;
      }
      // 数字以外で正しくない文字
      printError();
      return;
    }
  }
  // dotがあった場合
  if (isdot == true) {
    printAllType(std::stod(string));
    return;
  }
  try {
    printAllType(std::stoi(string));
  } catch (const std::exception& e) {
    hugeNumPrint(std::stod(string));
  }
  return;
}
