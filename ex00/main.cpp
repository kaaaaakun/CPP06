#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "usage : "<< std::endl;
		return 0;
	}
	std::string str = argv[1];
	convert(str);
	return 0;
}
