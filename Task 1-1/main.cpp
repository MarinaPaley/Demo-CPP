// see https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/math-constants?view=msvc-160
#define _USE_MATH_DEFINES // for C++

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
    const auto x = 1.426;
    const auto y = -1.22;
    const auto z = 3.5;

    const auto a = 2.0 * cos(x - M_PI / 6.0) / (0.5 + sin(y) * sin(y));
    const auto b = 1.0 + z * z / (3.0 + z * z / 5.0);

    cout << "x = " << x << "; "
         << "Y = " << y << "; "
         << "z = " << z << ";\n";

    cout << setprecision(10)
         << "a = " << a << "; "
         << "b = " << b << ";"
         << endl;

    return 0;
}
