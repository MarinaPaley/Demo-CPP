// see https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/math-constants?view=msvc-160
#define _USE_MATH_DEFINES // for C++

#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

/**
 * \brief Функция расчета для случая, когда x > a.
 * \param x Входная величина.
 * \param a Входная величина.
 * \return Значение функции.
 */
double F1(const double x, const double a);
/**
 * \brief Функция расчета для случая, когда x <= a.
 * \param x Входная величина.
 * \param a Входная величина.
 * \return Значение функции.
 */
double F2(const double x, const double a);

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
    const auto THRESHOLD = 2.5;
    double x;
    cout << "Введите переменную x = ";
    cin >> x;
    double result;
    if (x > THRESHOLD)
    {
        result = F1(x, THRESHOLD);
    }
    else
    {
        result = F2(x, THRESHOLD);
    }
    cout << "y = " << setprecision(15) << result << endl;
    return 0;
}

double F1(const double x, const double a)
{
    return x * pow(x - a, 1.0 / 3.0);
}

double F2(const double x, const double a)
{
    return x * sin(a * x);
}