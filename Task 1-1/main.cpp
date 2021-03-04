// see https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/math-constants?view=msvc-160
#define _USE_MATH_DEFINES // for C++

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;



int main()
{

    const double x = 1.426;
    const double y = -1.22;
    const double z = 3.5;

    const auto a = (2 * cos(x - M_PI / 6.0)) / (0.5 + sin(y) * sin(y));
    const auto b = 1 + (z * z / (3 + z * z / 5.0));

    cout << "x = " << x << "; y = " << y << "; z = " << z << "\n";
    cout << setprecision(10) << "a = "<<a << "; b = " << b << endl;

    return 0;
}
