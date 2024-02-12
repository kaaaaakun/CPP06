#include <iostream>
#include <math.h>

using namespace std;

//bool my_is_nan(long long int x){
//	if (x != x)
//		return 0;
//	return 1;
//}

//bool my_is_nan(double x){
//	if (x != x)
//		return 0;
//	return 1;
//}

bool my_is_nan ( double x ) { return (x != x); }
bool my_is_nan ( float x ) { return (x != x); }
bool my_is_nan ( int x ) { return (x != x); }

int main(int argc, char const *argv[]){
	double log_x = log(0);
	double exp_ma = exp(750);
	float f = log(0) - 100;

	cout << log_x << " : " << my_is_nan(log_x) << endl;
	cout << exp_ma << " : " << my_is_nan(exp_ma) << endl;
	cout << 0 / 0 << " : " << my_is_nan(static_cast<double>(0/0)) << endl;
	cout << 0 << " : " << my_is_nan(static_cast<float>(0)) << endl;
	cout << 1 << " : " << my_is_nan(static_cast<float>(1)) << endl;
	cout << f << " : " << my_is_nan(f) << endl;

	cout << exp_ma / exp_ma <<" : " << my_is_nan(exp_ma / exp_ma) <<   endl;
	cout << log_x / log_x << " : " << my_is_nan(log_x / log_x) << endl;
	cout << exp_ma + log_x << " : " << my_is_nan(exp_ma + log_x) << endl;

	return 0;
}

//#include <cstdint>
//
//union ieee_double_shape_type {
//  double value;
//  struct {
//    #if defined(__BIG_ENDIAN__)
//      std::uint32_t msw;
//      std::uint32_t lsw;
//    #else
//      std::uint32_t lsw;
//      std::uint32_t msw;
//    #endif
//  } parts;
//};
//
//#define EXTRACT_WORDS(ix0, ix1, d) \
//  do { \
//    ieee_double_shape_type ew_u; \
//    ew_u.value = (d); \
//    (ix0) = ew_u.parts.msw; \
//    (ix1) = ew_u.parts.lsw; \
//  } while (0)
//

//int main() {
//  double num1 = 3.14;
//  double num2 = 0.0 / 0.0;
//
//  if (isnan(num1))
//    std::cout << "num1 is NaN" << std::endl;
//  else
//    std::cout << "num1 is not NaN" << std::endl;
//
//  if (isnan(num2))
//    std::cout << "num2 is NaN" << std::endl;
//  else
//    std::cout << "num2 is not NaN" << std::endl;
//
//  return 0;
//}
//
