#include "ScalarConverter.hpp"

// Canonical Form
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
  (void)other;
  return *this;
}

char ScalarConverter::toChar(const std::string& str) {
  // 1文字&数字以外の処理
  int i = std::stoi(str);
  if (std::isprint(i) == 0) {
    throw std::invalid_argument("Non displayable");
  }
  return i;
}

bool ScalarConverter::isOnlyChar(std::string& testStr) {
  unsigned int i = 0;
  for (; i < testStr.length(); i++) {
    if (isdigit(testStr[i]) != 0) {
      break;
    }
  }
  if (i == testStr.length()) {
    return true;
  }
  return false;
}

bool ScalarConverter::isValidnumber(std::string& testStr) {
  unsigned int i = 0;
  bool isdot = false;
  for (; i < testStr.length(); i++) {
    // 数字以外の時
    if (isdigit(testStr[i]) == 0) {
      // 負の数の時
      if (i == 0 && testStr[i] == '-') {
        continue;
      }
      // 小数点の時
      if (testStr[i] == '.' && isdot == false && i != 0) {
        isdot = true;
        continue;
      }
      if ((testStr[i] == 'f' || testStr[i] == 'F') &&
          i == testStr.length() - 1) {
        testStr = testStr.substr(0, testStr.length() - 1);
        return true;
      }
      return false;
    }
  }
  return true;
}

bool ScalarConverter::isConvertible(std::string& testStr) {
  // 空文字列の時
  if (testStr.empty()) {
    return false;
  }
  // 1文字の時
  if (testStr.length() == 1) {
    if (isdigit(testStr[0]) == 0) {
      testStr = std::to_string(static_cast<int>(testStr[0]));
    }
    return true;
  }
  // 数字以外の時
  if (isOnlyChar(testStr) == true) {
    return true;
  }
  // 数字の時
  if (isValidnumber(testStr) == false) {
    return false;
  }
  return true;
}

void ScalarConverter::print_error() {
  std::cerr << "Char  : impossible" << std::endl;
  std::cerr << "Int   : impossible" << std::endl;
  std::cerr << "Float : impossible" << std::endl;
  std::cerr << "Double: impossible" << std::endl;
}

void ScalarConverter::convert(std::string testStr) {
  // 文字列だった時のエラー処理
  if (isConvertible(testStr) == false) {
    print_error();
    return;
  }
  try {
    // charに変換
    char c = toChar(testStr);
    std::cout << "Char  : '" << c << "'" << std::endl;

  } catch (const std::exception& e) {
    std::cerr << "Char  : impossible" << std::endl;
  }
  try {
    // intに変換
    int i = std::stoi(testStr);
    std::cout << "Int   : " << i << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Int   : impossible" << std::endl;
  }
  try {
    // floatに変換
    float f = std::stof(testStr);
    std::cout << "Float : " << std::fixed << std::setprecision(1) << f << "f"
              << std::endl;

  } catch (const std::exception& e) {
    std::cerr << "Float : impossible" << std::endl;
  }
  try {
    // doubleに変換
    double d = std::stod(testStr);
    std::cout << "Double: " << std::fixed << std::setprecision(1) << d
              << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Double: impossible" << std::endl;
  }

  return;
}
