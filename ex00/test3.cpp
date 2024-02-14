#include <iostream>
#include <sstream>
#include <cstring>
#include <iomanip>

//// 文字列をcharに変換する関数
//char toChar(const std::string& str) {
//    if (str.length() != 1) {
//        throw std::invalid_argument("Invalid input for char conversion");
//    }
//    return str[0];
//}

char toChar(const std::string& str) {
	//1文字&数字以外の処理
	int i = std::stoi(str);
	if (std::isprint(i) == 0) {
		throw std::invalid_argument("Non displayable");
	}
	return i;
}

// 文字列をintに変換する関数
int toInt(const std::string& str) { return std::stoi(str);}

// 文字列をfloatに変換する関数
float toFloat(const std::string& str) {
    std::stringstream ss(str);
    float result;
    if (!(ss >> result) || !ss.eof()) {
        throw std::invalid_argument("Invalid input for float conversion");
    }
    return result;
}

// 文字列をdoubleに変換する関数
double toDouble(const std::string& str) {
    std::stringstream ss(str);
    double result;
    if (!(ss >> result) || !ss.eof()) {
        throw std::invalid_argument("Invalid input for double conversion");
    }
    return result;
}

bool iserror(std::string &testStr) {
	//空文字列の時
	if (testStr.empty()) {
		return false;
	}
	//1文字の時
	if (testStr.length() == 1) {
		if (isdigit(testStr[0]) == 0) {
			testStr = std::to_string(static_cast<int>(testStr[0]));
		}
			return true;
	}
	bool isdot = false;
	int i = 0;
	for (; i < testStr.length(); i++) {
		//数字以外の時
		if (isdigit(testStr[i]) == 0) {
			//負の数の時
			if (i == 0 && testStr[i] == '-') {
				continue;
			}
			//小数点の時
			if (testStr[i] == '.' && isdot == false && i != 0) {
				isdot = true;
				continue;
			}
			if ((testStr[i] == 'f' || testStr[i] == 'F') && i == testStr.length() - 1) {
				testStr = testStr.substr(0, testStr.length() - 1);
				return true;
			}
			
			return false;
		}
	}
	return true;
}

void print_error() {
	std::cerr << "Error : impossible" << std::endl;
}

int convert(std::string testStr) {
	std::cout << "\ntestStr: " << testStr << std::endl;
	//文字列だった時のエラー処理
	if (iserror(testStr) == false) {
		print_error();
		return 1;
	}
    try {
        // charに変換
        char c = toChar(testStr);
        std::cout << "Char  : " << c << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }
    try {
        // intに変換
        int i = toInt(testStr);
        std::cout << "Int   : " << i << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }
    try {
        // floatに変換
        float f = toFloat(testStr);
        std::cout << "Float : " << std::fixed << std::setprecision(1) << f << "f"<< std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }
    try {
        // doubleに変換
        double d = toDouble(testStr);
        std::cout << "Double: " << std::fixed << std::setprecision(1) << d << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }

    return 0;
}

int main(int argc, char* argv[]) {
//	if (argc != 2) {
//		std::cerr << "Usage: " << argv[0] << " <test string>" << std::endl;
//		return 1;
//	}
	std::cout << "\nエラーの文字列" << std::endl;
	convert("");
	convert("aaaaaa");
	convert("1.1.1");
	convert("");
	convert(".11");
	convert("nan");
	convert("inf");

	std::cout << "\n正常の文字列" << std::endl;
	convert("a");
	convert("1");
	convert("-10");
	convert("10");
	convert("2147483647");
	convert("-2147483648");
	convert("42.0f");
	convert("42.0F");
	convert("42.0");
	convert("42.1");
	return 0;
}

