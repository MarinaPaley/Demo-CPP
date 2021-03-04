// see https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/math-constants?view=msvc-160
#define _USE_MATH_DEFINES // for C++

#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

double f1(const double x, const double a);
double f2(const double x, const double a);


int main()
{
    const auto a = 2.5;
    double x;
    cout << "Введите переменную x = ";
    cin >> x;
    if (x > a)
    {
        cout << "y = " << f1(x, a);
    }
    else
    {
        cout << "y = " << f2(x, a);
    }

    return 0;
}

double f1(const double x, const double a)
{
    return x * pow(x - a, 1.0 / 3.0);
}

double f2(const double x, const double a)
{
    return x * sin(a * x);
}