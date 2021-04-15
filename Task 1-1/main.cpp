// see https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/math-constants?view=msvc-160
#define _USE_MATH_DEFINES // for C++

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * \brief Функция расчета значения переменной по некоторой формуле.
 * \param x входной параметр.
 * \param y входной параметр.
 * \return Значение функции для константных значений x и y.
 */
double GetA(const double x, const double y);

/**
 * \brief Функция расчета значения переменной по некоторой формуле.
 * \param z входной параметр.
 * \return Значение функции для константного значения z.
 */
double GetB(const double z);

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
    const auto x = 1.426;
    const auto y = -1.22;
    const auto z = 3.5;

    const auto a = GetA(x, y);
    const auto b = GetB(z);

    cout << "x = " << x << "; "
         << "Y = " << y << "; "
         << "z = " << z << ";\n";

    cout << setprecision(10)
         << "a = " << a << "; "
         << "b = " << b << ";"
         << endl;

    return 0;
}

double GetA(const double x, const double y)
{
    return 2.0 * cos(x - M_PI / 6.0) / (0.5 + sin(y) * sin(y));
}

double GetB(const double z)
{
    return  1.0 + z * z / (3.0 + z * z / 5.0);
}
