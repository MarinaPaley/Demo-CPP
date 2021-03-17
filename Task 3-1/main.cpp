// see https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/math-constants?view=msvc-160
#define _USE_MATH_DEFINES // for C++

#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;


/**
 * \brief Функция расчета y.
 * \param x Входной параметр.
 * \param y Значение функции в точке x, при возможности расчета.
 * \return true, если функция определена в заданной точке x.
 */
bool IsCalculated(const double x, double& y);

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
    const auto leftBound = 2;
    const auto rightBound = 3.0;
    const auto step = 0.1;

    auto x = leftBound;
    cout << "  x" << setw(15) << "y\n";
    while ((x < rightBound) || (abs(x - rightBound) < step))
    {
        double y;
        if (IsCalculated(x, y))
        {
            cout << setprecision(2) << x << setw(15)
                 << setprecision(5) << y << '\n';
        }
        else
        {
            cout << setprecision(2) << x << setw(15)
                 << "not defined \n";
        }
        x += step;
    }
    return 0;
}

bool IsCalculated(const double x, double& y)
{
    const auto isCalculted = x >= 0;
    if (isCalculted)
    {
        y = 3 * sin(sqrt(x)) + 0.39 * x - 3.8;
    }
    return isCalculted;
    
}